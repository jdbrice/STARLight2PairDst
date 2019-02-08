

TH1 * project( TString n, TH2* h2, float x1, float x2 ){
	TAxis * xa = h2->GetXaxis();
	int b1 = xa->FindBin( x1 );
	int b2 = xa->FindBin( x2 );

	return h2->ProjectionY( TString::Format( "%s_%d_%d", n.Data(), b1, b2 ), b1, b2 );
}



TF1* expoFit( TH1 * h, float *mean, float *error ){

	TF1 * ff = new TF1( TString::Format( "%s_ff", h->GetName() ), "[0] * exp(  [1]*x )", 0.001, 0.015 );
	h->Fit( ff, "R", "", 0.001, 0.015 );

	*mean = sqrt( -1.0 / ff->GetParameter( 1 ) );
	cout << "mean = " << *mean << endl;
	*error = abs( sqrt( -1.0 / (ff->GetParameter( 1 ) + ff->GetParError( 1 ) ) ) - *mean );
	cout << "error = " << *error << endl;

	ff->Write();

	return ff;
}



void compare_starlight_curves(){

	TFile *fAuAu = new TFile( "AuAu_starlight.root" );
	TFile *fRun12UU = new TFile( "Run12UU_starlight.root" );

	TH2 * h2AuAu = (TH2*)fAuAu->Get( "pT2_m" );
	TH2 * h2UU = (TH2*)fRun12UU->Get( "pT2_m" );

	vector<float> sbins = { 0.0, 0.4, 0.76, 1.2, 2.6, 5.0 };

	TH1 * hFrame = new TH1F( "hframe", "", 300, 0, 3 ); 
	TH1 * hslAuAu = new TH1F( "hslAuAu", "", sbins.size()-1, sbins.data() );
	TH1 * hslUU = new TH1F( "hslUU", "", sbins.size()-1, sbins.data() );

	TFile *foutput = new TFile( "SL_AuAu_and_UU_curves.root", "RECREATE" );

	float step = 0.1;
	for ( int i = 1; i < sbins.size()-1; i++ ){
		float x1 = sbins[i];
		float x2 = sbins[i+1];

		TH1 * hAuAu = project( "hAuAu", h2AuAu, x1, x2 );
		TH1 * hUU = project( "hUU", h2UU, x1, x2 );

		hAuAu->Write();
		hUU->Write();

		int mBin = hslUU->GetXaxis()->FindBin( (x1+x2)/2.0 );

		hAuAu->GetXaxis()->SetRangeUser( 0, 0.015 );
		float v = sqrt(hAuAu->GetMean()) * 1000;
		float re = (double)hAuAu->GetMeanError() / hAuAu->GetMean();
		expoFit( hAuAu, &v, &re );
		hslAuAu->SetBinContent( mBin, v * 1000 );
		// hslAuAu->SetBinError( mBin, (0.5 * re * v) );

		hUU->GetXaxis()->SetRangeUser( 0, 0.015 );
		v = sqrt(hUU->GetMean()) * 1000;
		re = (double)hUU->GetMeanError() / hUU->GetMean();
		expoFit( hUU, &v, &re );
		hslUU->SetBinContent( mBin, v*1000 );
		// hslUU->SetBinError( mBin, (0.5 * re * v) );
	}



	// hFrame->SetMaximum( 50 );
	// hFrame->Draw();
	// hslAuAu->SetLineColor(kRed);
	// hslAuAu->SetMarkerColor(kRed);
	// hslAuAu->SetMarkerStyle(23);
	// hslAuAu->Draw("same");

	// hslUU->SetLineColor(kBlack);
	// hslUU->SetMarkerColor(kBlack);
	// hslUU->SetMarkerStyle(29);
	// hslUU->Draw("same");

	
	hslAuAu->Write();
	hslUU->Write();


}