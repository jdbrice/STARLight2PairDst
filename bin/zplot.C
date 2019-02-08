



void zplot(){

	TFile *f = new TFile( "AuAu_starlight.root" );

	gStyle->SetOptStat( 0 );

	TCanvas * can = new TCanvas( "can", "", 1200, 900 );
	can->SetRightMargin( 0.05 );
	can->SetTopMargin( 0.06 );

	TH1 * hpt = (TH1*)f->Get( "pT2_m0" );
	TH1 * hpt2 = (TH1*)f->Get( "pT2_m0" );

	TH1 * hz0 = (TH1*)hpt2->Clone( "hz0" );
	TH1 * hz1 = (TH1*)hpt2->Clone( "hz1" );;//new TH1F( "hz1", "", 24, 0, 0.006);
	TH1 * hz2 = (TH1*)hpt2->Clone( "hz2" );

	double x[] = { 0.0002, 0.00065, 0.00125, 0.00205, 0.00305, 0.00425, 0.00565 };
	double y[] = { 0.0185, 0.0191, 0.0143, 0.00972, 0.00591, 0.00480, 0.00287 };
	double ex[] = {2.00e-04, 2.50e-04, 3.50e-04, 4.50e-04, 5.50e-04, 6.50e-04, 7.50e-04}; 
	double ey[] = { 1.58e-03, 1.35e-03, 1.07e-03, 8.80e-04, 7.47e-04, 6.41e-04, 5.71e-04 };
	double eySys[] = { 2.89e-03, 2.92e-03, 2.16e-03, 1.44e-03, 9.04e-04, 7.43e-04, 4.69e-04 };

	for ( int i = 0; i < 7; i++ ){
		double pt = x[i];
		y[i] = y[i] * pt;
		ey[i] = ey[i] * pt;
		eySys[i] = eySys[i] * pt;
		ex[i] = ex[i]/2.0;
	}

	hz1->Reset();
	hz2->Reset();
	hz0->Reset();
	for ( int i = 1; i <= hz0->GetXaxis()->GetNbins(); i++ ){
		double N = hpt2->GetBinContent( i );
		double pt = sqrt(hpt2->GetBinCenter( i ));

		// pt=pt*pt;
		hz0->SetBinContent( i, N );
	}
	// hz0->Scale( 4e-5 / hz0->Integral(), "width" );

	cout << "Scale Factor = " << 3.41e-2 / hz0->GetBinContent( hz0->GetXaxis()->FindBin( 2e-4 ) ) << endl;
	hz0->Scale( 3.41e-2 / hz0->GetBinContent( hz0->GetXaxis()->FindBin( 2e-4 ) ) );

	for ( int i = 1; i <= hz0->GetXaxis()->GetNbins(); i++ ){
		double N = hz0->GetBinContent( i );
		double pt = sqrt(hz0->GetBinCenter( i ));
		// pt = pt*pt;
		// pt=1;
		hz0->SetBinContent( i, N * pt * pt );
		hz0->SetBinError( i, 0 );
	}

	// TAxis * ax = hz1->GetXaxis();
	// for ( int i = 0; i < 7; i++ ){
	// 	int b = ax->FindBin( x[i] );
	// 	float pt = sqrt( x[i] );
	// 	pt=1;
	// 	hz1->SetBinContent( b, y[i] * pt );
	// 	hz1->SetBinError( b, (ey[i] / y[i]) *( y[i] * pt ) );
	// }

	// for ( int i = 0; i < 7; i++ ){
	// 	int b = ax->FindBin( x[i] );
	// 	float pt = sqrt( x[i] );
	// 	pt=1;
	// 	hz2->SetBinContent( b, y[i] * pt );
	// 	hz2->SetBinError( b, (eySys[i] / y[i]) *( y[i] * pt ) );
	// }

	TGraphErrors * gz1 = new TGraphErrors( 7, x, y, ex, ey );
	TGraphErrors * gz2 = new TGraphErrors( 7, x, y, ex, eySys );

	
	hz0->SetLineColor(kOrange+7);
	hz0->SetLineWidth(8);
	hz0->SetLineStyle(3);
	
	hz0->SetTitle( "" );
	hz0->GetXaxis()->SetTitle( "p_{T}^{2} (GeV/c)^{2}" );
	hz0->GetXaxis()->SetTitleSize( 16.0 / 360.0 );
	hz0->GetYaxis()->SetTitle( "d^{2}N/(dp_{T}dy) (GeV/c)^{-1}" );
	hz0->GetYaxis()->SetTitleSize( 18.0 / 360.0 );
	hz0->GetYaxis()->SetTitleOffset( 0.8 );
	hz0->SetMaximum( 0.4e-4 );

	hz0->Draw("l");
	hz0->GetXaxis()->SetRangeUser( 0, 0.007 );

	gz2->SetFillColorAlpha( kGray, 0.75 );
	gz2->Draw( "same pe2" );

	gz1->SetMarkerStyle( 29 );
	gz1->SetMarkerSize( 4 );
	gz1->SetMarkerColor(kBlack);
	gz1->SetLineColor(kBlack);
	gz1->SetLineWidth(2);
	gz1->Draw( "same pe" );

	TLatex tl;
	tl.SetTextFont(42);
	tl.SetTextSize( 22.0 / 360.0 );
	tl.DrawLatexNDC( 0.15, 0.15, "0.4 - 0.76 GeV/c^{2}" );
	tl.SetTextSize( 16.0 / 360.0 );
	tl.DrawLatexNDC( 0.65, 0.71, "p_{T}^{e} > 0.2 GeV/c" );
	tl.DrawLatexNDC( 0.65, 0.65, "|#eta^{e}| < 1, |y^{ee}| < 1" );

	TLegend * leg = new TLegend( 0.5, 0.75, 0.945, 0.934 );
	leg->SetBorderSize(0);
	leg->AddEntry( gz1, "60-80% Au+Au", "p" );
	leg->AddEntry( hz0, "#gamma#gamma #rightarrow ee (STARlight)" );
	leg->Draw("asme");


	can->Print( "dNdpTdy_versus_pT2_mass0.pdf" );
	
}