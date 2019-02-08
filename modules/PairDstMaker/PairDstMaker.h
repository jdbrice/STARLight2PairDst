#ifndef PAIR_DST_MAKER_H
#define PAIR_DST_MAKER_H


#include "HistoAnalyzer.h"
#include "XmlRange.h"

#include "vendor/loguru.h"

#include "TNamed.h"
#include "TTree.h"


#include "FemtoDstFormat/BranchReader.h"
#include "FemtoDstFormat/BranchWriter.h"
#include "FemtoDstFormat/TClonesArrayReader.h"
#include "FemtoDstFormat/FemtoEvent.h"
#include "FemtoDstFormat/FemtoTrack.h"
#include "FemtoDstFormat/FemtoBTofPidTraits.h"
#include "FemtoDstFormat/FemtoTrackProxy.h"

#include "PairDstFormat/FemtoPair.h"


// template <>
// TString XmlConfig::get<TString>( string path ) const {
// 	TString r( getString( path ) );
// 	return r;
// }

// template <>
// TString XmlConfig::get<TString>( string path, TString dv ) const {
// 	if ( !exists( path ) )
// 		return dv;
// 	TString r( getString( path ) );
// 	return r;
// }

class PairDstMaker : public HistoAnalyzer
{
protected:

	BranchReader<FemtoEvent> _fer;
	TClonesArrayReader<FemtoTrack> _ftr;
	TClonesArrayReader<FemtoBTofPidTraits> _fbtofr;


	TTree * _pairDst = nullptr;
	BranchWriter<FemtoPair> _fpw;
	FemtoPair _pair; 

	int maxEvents;
	bool starAcc = false;

	double daughterMass = 0.0005109989461;

public:

	const int DEBUG = 1;
	PairDstMaker() {}
	~PairDstMaker() {}

	virtual void initialize(){
		HistoAnalyzer::initialize();

		book->cd();

		this->_pairDst = new TTree( "PairDst", "" );
		this->_fpw.createBranch( this->_pairDst, "Pairs" );


		maxEvents = config.get<int>( "maxEvents", -1 );
		daughterMass = config.get<double>( "daughterMass", 0.0005109989461 );
		starAcc = config.get<bool>( "starAcc", false ); // apply STAR acceptance?

		LOG_F( INFO, "Daughter Mass = %f", daughterMass );

	}
protected:

	// void addPair(FemtoEvent * event, FemtoTrackProxy &p1, FemtoTrackProxy &p2){
		
	// 	if ( p1._track->mId == p2._track->mId) return;

	// 	this->_pair.reset();
	// 	this->_pair.mVertexZ              = event->mPrimaryVertex_mX3;
	// 	this->_pair.mDeltaVertexZ         = event->mPrimaryVertex_mX3 - event->mVpdVz;
	// 	this->_pair.mGRefMult             = event->mGRefMult;

	// 	this->_pair.d1_mPt                = p1._track->mPt;
	// 	this->_pair.d1_mEta               = p1._track->mEta;
	// 	this->_pair.d1_mPhi               = p1._track->mPhi;
	// 	this->_pair.d1_mId                = p1._track->mId;
	// 	this->_pair.d1_mNHitsFit          = p1._track->mNHitsFit;
	// 	this->_pair.d1_mNHitsMax          = p1._track->mNHitsMax;
	// 	this->_pair.d1_mNHitsDedx         = p1._track->mNHitsDedx;
	// 	this->_pair.d1_mNSigmaPion        = p1._track->mNSigmaPion;
	// 	this->_pair.d1_mNSigmaKaon        = p1._track->mNSigmaKaon;
	// 	this->_pair.d1_mNSigmaProton      = p1._track->mNSigmaProton;
	// 	this->_pair.d1_mNSigmaElectron    = p1._track->mNSigmaElectron;
	// 	this->_pair.d1_mDCA               = p1._track->mDCA;
	// 	// this->_pair.d1_mPid               = p1._pid;

	// 	if ( nullptr != p1._btofPid ){
	// 		this->_pair.d1_mYLocal               = p1._btofPid->mBTofYLocal;
	// 		this->_pair.d1_mZLocal               = p1._btofPid->mBTofZLocal;
	// 		this->_pair.d1_mTof                  = p1._btofPid->mBTof;
	// 		this->_pair.d1_mLength               = p1._btofPid->mLength;
	// 		this->_pair.d1_mMatchFlag            = p1._btofPid->mBTofMatchFlag;
	// 	} else {
	// 		this->_pair.d1_mYLocal               = -999;
	// 		this->_pair.d1_mZLocal               = -999;
	// 		this->_pair.d1_mTof                  = 0;
	// 		this->_pair.d1_mLength               = 0;
	// 		this->_pair.d1_mMatchFlag            = 0;
	// 	}


	// 	this->_pair.d2_mPt                = p2._track->mPt;
	// 	this->_pair.d2_mEta               = p2._track->mEta;
	// 	this->_pair.d2_mPhi               = p2._track->mPhi;
	// 	this->_pair.d2_mId                = p2._track->mId;
	// 	this->_pair.d2_mNHitsFit          = p2._track->mNHitsFit;
	// 	this->_pair.d2_mNHitsMax          = p2._track->mNHitsMax;
	// 	this->_pair.d2_mNHitsDedx         = p2._track->mNHitsDedx;
	// 	this->_pair.d2_mNSigmaPion        = p2._track->mNSigmaPion;
	// 	this->_pair.d2_mNSigmaKaon        = p2._track->mNSigmaKaon;
	// 	this->_pair.d2_mNSigmaProton      = p2._track->mNSigmaProton;
	// 	this->_pair.d2_mNSigmaElectron    = p2._track->mNSigmaElectron;
	// 	this->_pair.d2_mDCA               = p2._track->mDCA;
	// 	// this->_pair.d2_mPid               = p2._pid;

	// 	if ( nullptr != p2._btofPid ){
	// 		this->_pair.d2_mYLocal               = p2._btofPid->mBTofYLocal;
	// 		this->_pair.d2_mZLocal               = p2._btofPid->mBTofZLocal;
	// 		this->_pair.d2_mTof                  = p2._btofPid->mBTof;
	// 		this->_pair.d2_mLength               = p2._btofPid->mLength;
	// 		this->_pair.d2_mMatchFlag            = p2._btofPid->mBTofMatchFlag;
	// 	} else {
	// 		this->_pair.d2_mYLocal               = -999;
	// 		this->_pair.d2_mZLocal               = -999;
	// 		this->_pair.d2_mTof                  = 0;
	// 		this->_pair.d2_mLength               = 0;
	// 		this->_pair.d2_mMatchFlag            = 0;
	// 	}

	// 	TLorentzVector lv1, lv2, lv;

	// 	// // lv = p1._track->lv( 0.1056583745 ) + p2._track->lv( 0.1056583745 ); 
	// 	lv = p1._track->lv( daughterMass ) + p2._track->lv( daughterMass ); 

	// 	// // if ( lv.M() < 0.22 ){
	// 	// // 	LOG_F(INFO, "track1.pt, eta, phi = %f, %f, %f", p1._track->mPt, p1._track->mEta, p1._track->mPhi );
	// 	// // 	LOG_F(INFO, "track2.pt, eta, phi = %f, %f, %f", p2._track->mPt, p2._track->mEta, p2._track->mPhi );
	// 	// // }
		
	// 	this->_pair.mChargeSum = p1._track->mQ + p2._track->mQ;
	// 	this->_pair.mMass      = lv.M();
	// 	this->_pair.mPt        = lv.Pt();
	// 	this->_pair.mEta       = lv.PseudoRapidity();
	// 	this->_pair.mPhi       = lv.Phi();
	// 	this->_pair.mRapidity  = lv.Rapidity();

	// 	this->_fpw.set( this->_pair );
	// 	this->_pairDst->Fill();

	// }



	virtual void make(){
		LOG_F( INFO, "MAKE" );

		string starlight = config.get<string>( nodePath + ".input.TxtFile:url" );
		LOG_F( INFO, "Reading from %s", starlight.c_str() );
		ifstream infile( starlight.c_str() );

		int iEvent =0;
		while (infile) {
			string sEvent, sVertex, sTrack1, sTrack2;
			if (!getline( infile, sEvent )) break;
			if (!getline( infile, sVertex )) break;
			if (!getline( infile, sTrack1 )) break;
			if (!getline( infile, sTrack2 )) break;

			// cout << "track1 " << sTrack1 << endl;
			// cout << "track2 " << sTrack2 << endl;

			istringstream ss1( sTrack1 );
			istringstream ss2( sTrack2 );

			string nil;
			int gpid, nev, ntr, stopv, pdgid;
			float px1, py1, pz1;
			float px2, py2, pz2;

			nil = "";
			gpid = 0;
			nev = 0;
			ntr = 0;
			stopv = 0;
			pdgid = 0;
			px1 = py1 = pz1 = 0;
			px2 = py2 = pz2 = 0;

			ss1 >> nil >> gpid >> px1 >> py1 >> pz1 >> nev >> ntr >> stopv >> pdgid;
			ss2 >> nil >> gpid >> px2 >> py2 >> pz2 >> nev >> ntr >> stopv >> pdgid;

			TLorentzVector lv1, lv2, lv;
			lv1.SetXYZM( px1, py1, pz1, 0.0005109989461 );
			lv2.SetXYZM( px2, py2, pz2, 0.0005109989461 );

			lv = lv1 + lv2;

			this->_pair.reset();

			this->_pair.d1_mPt = lv1.Pt();
			this->_pair.d1_mEta = lv1.Eta();
			this->_pair.d1_mPhi = lv1.Phi();

			this->_pair.d2_mPt = lv2.Pt();
			this->_pair.d2_mEta = lv2.Eta();
			this->_pair.d2_mPhi = lv2.Phi();


			this->_pair.mMass     = lv.M();
			this->_pair.mPt       = lv.Pt();
			this->_pair.mEta      = lv.Eta();
			this->_pair.mPhi      = lv.Phi();
			this->_pair.mRapidity = lv.Rapidity();

			if ( starAcc ){
				if ( lv1.Pt() < 0.100 || fabs(lv1.Eta())>1.0 )
					continue;
				if ( lv2.Pt() < 0.100 || fabs(lv2.Eta())>1.0 )
					continue;
				if ( fabs(lv.Rapidity())>1.0 )
					continue;
				if ( fabs(lv.M())<1.0 )
					continue;
			}


			this->_fpw.set( this->_pair );
			this->_pairDst->Fill();

			iEvent++;

			if ( iEvent >= maxEvents && maxEvents > 0 )
				break;

		}
	}

	virtual void postMake(){
		

		this->_pairDst->Write();


	}

};


#endif