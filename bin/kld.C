

double metric_Dkl( float Qi, float Pi ){
	return Qi * log( Qi / Pi );
}

double metric_L1( float Qi, float Pi ){
	return abs( Qi - Pi );
}

double metric_L2( float Qi, float Pi, float Qie, float Pie ){
	return pow(abs( Qi - Pi ) / ( Qie + Pie ),2);
}

// sum{ Q[i] * log( Q[i] / P[i] ) }
double compute_metric( TH1 * h0, TH1 * h1, float x1 = 0 , float x2 = -1 ){

	int b1 = h0->GetXaxis()->FindBin(x1);
	int b2 = h0->GetXaxis()->FindBin(x2);

	if ( x2 < x1 )
		b2 = h0->GetXaxis()->GetNbins();

	double Dkl = 0;

	cout << "Dkl in (" << x1 << ", " << x2 << ")" << endl;
	for ( int i = b1; i <= b2; i++ ){
		float Qi = h1->GetBinContent( i );
		float Qie = h1->GetBinError( i );
		float Pi = h0->GetBinContent( i );
		float Pie = h0->GetBinError( i );

		

		if ( Pi <= 0  || Qi <= 0) {
			// cout << TString::Format( "i=%d : Qi=%f, Pi=%f\n", i, Qi, Pi );
			continue;
		}
		Dkl += metric_L2(Qi, Pi, Qie, Pie);
		//metric_Dkl( Qi, Pi );
	}

	return Dkl;
}

void kld(){

	TFile * fSL = new TFile( "AuAu_starlight.root" );
	TFile * fD = new TFile( "../../FemtoPairAnalysis/bin/AuAu.root" );

	vector<TH1*> hSL;
	vector<TH1*> hD;
	vector<TH1*> hkld;
	hSL.push_back( (TH1*)fSL->Get( "pT2_m0" ) );
	hSL.push_back( (TH1*)fSL->Get( "pT2_m1" ) );
	hSL.push_back( (TH1*)fSL->Get( "pT2_m2" ) );

	hD.push_back( (TH1*)fD->Get( "hPt2Mass0" ) );
	hD.push_back( (TH1*)fD->Get( "hPt2Mass1" ) );
	hD.push_back( (TH1*)fD->Get( "hPt2Mass2" ) );


	for ( int i = 0; i < hSL.size(); i++ ){
		hSL[i]->Scale( 1.0 / hSL[i]->Integral() );
		hD[i]->Scale( 1.0 / hD[i]->Integral() );
		double Dkl = compute_metric( hSL[i], hD[i], 0, 0.06 );
		cout << "Dkl [" << i << "] = " << Dkl << endl;
	}


}