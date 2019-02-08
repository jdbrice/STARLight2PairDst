#ifndef STARLIGHT_ANA_H
#define STARLIGHT_ANA_H


#include "TreeAnalyzer.h"
#include "XmlRange.h"
#include "RooPlotLib.h"
#include "Reporter.h"
#include "FitConfidence.h"
#include "HistoBins.h"

#include "vendor/loguru.h"

#include "TNamed.h"
#include "TTree.h"
#include "TLorentzVector.h"
#include "TGraphErrors.h"
#include "TLatex.h"

#include "TRandom3.h"


#include "FemtoDstFormat/BranchReader.h"


#include <algorithm>


class STARLightAna : public TreeAnalyzer
{
protected:

	BranchReader<FemtoPair> _fpr;
	float dTofCut = 0.2;
	float XeeCut = 0.2;
	float ScaleFactor = 1.0;

	float ZDCMin = 0;
	float ZDCMax = 0;

	float ZDCEastMin = 0;
	float ZDCEastMax = 0;
	float ZDCWestMin = 0;
	float ZDCWestMax = 0;

	TH2 * hEffRc = nullptr;
	TH2 * hEffMc = nullptr;
	TH2 * hEff   = nullptr;
	TH2 * hRapEff  = nullptr;
	TH3 * hEff3D  = nullptr;

	

public:

	const int DEBUG = 1;
	STARLightAna() {}
	~STARLightAna() {}

	virtual void initialize(){
		TreeAnalyzer::initialize();

		this->_fpr.setup( this->chain, "Pairs" );

		
		book->cd();

		
	}
protected:

	virtual void analyzeEvent(){
		FemtoPair * pair = this->_fpr.get();

		TLorentzVector lv1, lv2, lv;
		lv1.SetPtEtaPhiM( pair->d1_mPt, pair->d1_mEta, pair->d1_mPhi, 0.0005109989461 );
		lv2.SetPtEtaPhiM( pair->d2_mPt, pair->d2_mEta, pair->d2_mPhi, 0.0005109989461 );
		lv = lv1 + lv2;

		if ( pair->d1_mPt  < 0.200 || pair->d2_mPt < 0.200 || abs( pair->d1_mEta ) > 1.0 || abs( pair->d2_mEta ) > 1.0 ) return;
		if ( abs(lv.Rapidity()) > 1.0 ) return;

		TLorentzVector lvPositron = lv2;
		lvPositron.Boost( -(lv.BoostVector()) );
		TVector3 vbeam(0, 0, 1.0);

		TVector3 vPositron( lvPositron.Px(), lvPositron.Py(), lvPositron.Pz() );
		float costheta = cos( vPositron.Angle( vbeam ) );
		
		book->fill( "w3costhetaid2", lv.M(), fabs(costheta), 1.0 );

	} //analyzeEvent

};


#endif

