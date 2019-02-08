


void no_fit_compare(){

	TFile *fdAuAu = new TFile( "../../FemtoPairAnalysis/bin/AuAu.root" );
	TFile *fslAuAu = new TFile( "AuAu_starlight.root" );
	TFile *fdUU = new TFile( "../../FemtoPairAnalysis/bin/Run12UU.root" );
	TFile *fslUU = new TFile( "Run12UU_starlight.root" );

	TH1 * hslAuAupt2_m0 = (TH1*)fslAuAu->Get( "pT2_m0" );
	TH1 * hslAuAupt2_m1 = (TH1*)fslAuAu->Get( "pT2_m1" );
	TH1 * hslAuAupt2_m2 = (TH1*)fslAuAu->Get( "pT2_m2" );

	TH1 * hdAuAupt2_m0 = (TH1*)fdAuAu->Get( "hPt2Mass0" );
	TH1 * hdAuAupt2_m1 = (TH1*)fdAuAu->Get( "hPt2Mass1" );
	TH1 * hdAuAupt2_m2 = (TH1*)fdAuAu->Get( "hPt2Mass2" );

	hdAuAupt2_m0->GetXaxis()->SetRangeUser( 0, 0.03 );
	hdAuAupt2_m1->GetXaxis()->SetRangeUser( 0, 0.03 );
	hdAuAupt2_m2->GetXaxis()->SetRangeUser( 0, 0.03 );


	TH1 * hslUUpt2_m0 = (TH1*)fslUU->Get( "pT2_m0" );
	TH1 * hslUUpt2_m1 = (TH1*)fslUU->Get( "pT2_m1" );
	TH1 * hslUUpt2_m2 = (TH1*)fslUU->Get( "pT2_m2" );


	TH1 * hFrame = new TH1F( "hframe", "", 300, 0, 3 );
	double mbins[] = {0, 0.4, 0.76, 1.2, 2.6, 3.0}; 
	TH1 * hslAuAu = new TH1F( "hslAuAu", "", 5, mbins );
	TH1 * hdAuAu = new TH1F( "hdAuAu", "", 5, mbins );
	TH1 * hslUU = new TH1F( "hslUU", "", 5, mbins );

	cout << "AuAu pT2_m0 = " << hslAuAupt2_m0->GetMean() << " +/-" << hslAuAupt2_m0->GetMeanError() << endl;
	double v = sqrt(hslAuAupt2_m0->GetMean()) * 1000;
	hslAuAu->SetBinContent( 2, v );
	double re = (double)hslAuAupt2_m0->GetMeanError() / hslAuAupt2_m0->GetMean();
	hslAuAu->SetBinError( 2, (0.5 * re) * v );

	v = sqrt(hslAuAupt2_m1->GetMean()) * 1000;
	hslAuAu->SetBinContent( 3, v );
	re = (double)hslAuAupt2_m1->GetMeanError() / hslAuAupt2_m1->GetMean();
	hslAuAu->SetBinError( 3, (0.5 * re) * v );

	v = sqrt(hslAuAupt2_m2->GetMean()) * 1000;
	hslAuAu->SetBinContent( 4, v );
	re = (double)hslAuAupt2_m2->GetMeanError() / hslAuAupt2_m2->GetMean();
	hslAuAu->SetBinError( 4, (0.5 * re) * v );


	v = sqrt(hslUUpt2_m0->GetMean()) * 1000;
	hslUU->SetBinContent( 2, v );
	re = (double)hslUUpt2_m0->GetMeanError() / hslUUpt2_m0->GetMean();
	hslUU->SetBinError( 2, (0.5 * re) * v );

	v = sqrt(hslUUpt2_m1->GetMean()) * 1000;
	hslUU->SetBinContent( 3, v );
	re = (double)hslUUpt2_m1->GetMeanError() / hslUUpt2_m1->GetMean();
	hslUU->SetBinError( 3, (0.5 * re) * v );

	v = sqrt(hslUUpt2_m2->GetMean()) * 1000;
	hslUU->SetBinContent( 4, v );
	re = (double)hslUUpt2_m2->GetMeanError() / hslUUpt2_m2->GetMean();
	hslUU->SetBinError( 4, (0.5 * re) * v );



	v = sqrt(hdAuAupt2_m0->GetMean()) * 1000;
	hdAuAu->SetBinContent( 2, v );
	re = (double)hdAuAupt2_m0->GetMeanError() / hdAuAupt2_m0->GetMean();
	hdAuAu->SetBinError( 2, (0.5 * re) * v );
	cout << "v = " << v << " +/- " << (0.5 * re) * v << endl;

	v = sqrt(hdAuAupt2_m1->GetMean()) * 1000;
	hdAuAu->SetBinContent( 3, v );
	re = (double)hdAuAupt2_m1->GetMeanError() / hdAuAupt2_m1->GetMean();
	hdAuAu->SetBinError( 3, (0.5 * re) * v );

	v = sqrt(hdAuAupt2_m2->GetMean()) * 1000;
	hdAuAu->SetBinContent( 4, v );
	re = (double)hdAuAupt2_m2->GetMeanError() / hdAuAupt2_m2->GetMean();
	hdAuAu->SetBinError( 4, (0.5 * re) * v );
	

	hFrame->SetMaximum( 50 );
	hFrame->SetMinimum( 15 );
	hFrame->Draw();
	hslAuAu->SetMarkerStyle( 24 );
	hslAuAu->Draw("same");

	hdAuAu->SetMarkerStyle( 28 );
	hdAuAu->Draw("same");

	hslUU->SetMarkerStyle( 23 );
	hslUU->SetLineColor( kRed );
	hslUU->Draw("same" );


}

