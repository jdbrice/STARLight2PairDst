// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME modulesdIPairDstFormatdIDictionaryFemtoPair

/*******************************************************************/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define G__DICTIONARY
#include "RConfig.h"
#include "TClass.h"
#include "TDictAttributeMap.h"
#include "TInterpreter.h"
#include "TROOT.h"
#include "TBuffer.h"
#include "TMemberInspector.h"
#include "TInterpreter.h"
#include "TVirtualMutex.h"
#include "TError.h"

#ifndef G__ROOT
#define G__ROOT
#endif

#include "RtypesImp.h"
#include "TIsAProxy.h"
#include "TFileMergeInfo.h"
#include <algorithm>
#include "TCollectionProxyInfo.h"
/*******************************************************************/

#include "TDataMember.h"

// Since CINT ignores the std namespace, we need to do so in this file.
namespace std {} using namespace std;

// Header files passed as explicit arguments
#include "FemtoPair.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static void *new_FemtoPair(void *p = 0);
   static void *newArray_FemtoPair(Long_t size, void *p);
   static void delete_FemtoPair(void *p);
   static void deleteArray_FemtoPair(void *p);
   static void destruct_FemtoPair(void *p);
   static void streamer_FemtoPair(TBuffer &buf, void *obj);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::FemtoPair*)
   {
      ::FemtoPair *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::FemtoPair >(0);
      static ::ROOT::TGenericClassInfo 
         instance("FemtoPair", ::FemtoPair::Class_Version(), "FemtoPair.h", 6,
                  typeid(::FemtoPair), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::FemtoPair::Dictionary, isa_proxy, 16,
                  sizeof(::FemtoPair) );
      instance.SetNew(&new_FemtoPair);
      instance.SetNewArray(&newArray_FemtoPair);
      instance.SetDelete(&delete_FemtoPair);
      instance.SetDeleteArray(&deleteArray_FemtoPair);
      instance.SetDestructor(&destruct_FemtoPair);
      instance.SetStreamerFunc(&streamer_FemtoPair);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::FemtoPair*)
   {
      return GenerateInitInstanceLocal((::FemtoPair*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::FemtoPair*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr FemtoPair::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *FemtoPair::Class_Name()
{
   return "FemtoPair";
}

//______________________________________________________________________________
const char *FemtoPair::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::FemtoPair*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int FemtoPair::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::FemtoPair*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *FemtoPair::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::FemtoPair*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *FemtoPair::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::FemtoPair*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void FemtoPair::Streamer(TBuffer &R__b)
{
   // Stream an object of class FemtoPair.

   UInt_t R__s, R__c;
   if (R__b.IsReading()) {
      Version_t R__v = R__b.ReadVersion(&R__s, &R__c); if (R__v) { }
      FemtoDstBranch::Streamer(R__b);
      R__b >> mVertexZ;
      R__b >> mDeltaVertexZ;
      R__b >> mGRefMult;
      R__b >> mChargeSum;
      R__b >> mPt;
      R__b >> mEta;
      R__b >> mPhi;
      R__b >> mMass;
      R__b >> mRapidity;
      R__b >> d1_mYLocal;
      R__b >> d1_mZLocal;
      R__b >> d1_mTof;
      R__b >> d1_mMatchFlag;
      R__b >> d1_mLength;
      R__b >> d1_mPt;
      R__b >> d1_mEta;
      R__b >> d1_mPhi;
      R__b >> d1_mId;
      R__b >> d1_mNHitsFit;
      R__b >> d1_mNHitsMax;
      R__b >> d1_mNHitsDedx;
      R__b >> d1_mNSigmaPion;
      R__b >> d1_mNSigmaKaon;
      R__b >> d1_mNSigmaProton;
      R__b >> d1_mNSigmaElectron;
      R__b >> d1_mDCA;
      R__b >> d1_mPid;
      R__b >> d2_mYLocal;
      R__b >> d2_mZLocal;
      R__b >> d2_mTof;
      R__b >> d2_mMatchFlag;
      R__b >> d2_mLength;
      R__b >> d2_mPt;
      R__b >> d2_mEta;
      R__b >> d2_mPhi;
      R__b >> d2_mId;
      R__b >> d2_mNHitsFit;
      R__b >> d2_mNHitsMax;
      R__b >> d2_mNHitsDedx;
      R__b >> d2_mNSigmaPion;
      R__b >> d2_mNSigmaKaon;
      R__b >> d2_mNSigmaProton;
      R__b >> d2_mNSigmaElectron;
      R__b >> d2_mDCA;
      R__b >> d2_mPid;
      R__b.CheckByteCount(R__s, R__c, FemtoPair::IsA());
   } else {
      R__c = R__b.WriteVersion(FemtoPair::IsA(), kTRUE);
      FemtoDstBranch::Streamer(R__b);
      R__b << mVertexZ;
      R__b << mDeltaVertexZ;
      R__b << mGRefMult;
      R__b << mChargeSum;
      R__b << mPt;
      R__b << mEta;
      R__b << mPhi;
      R__b << mMass;
      R__b << mRapidity;
      R__b << d1_mYLocal;
      R__b << d1_mZLocal;
      R__b << d1_mTof;
      R__b << d1_mMatchFlag;
      R__b << d1_mLength;
      R__b << d1_mPt;
      R__b << d1_mEta;
      R__b << d1_mPhi;
      R__b << d1_mId;
      R__b << d1_mNHitsFit;
      R__b << d1_mNHitsMax;
      R__b << d1_mNHitsDedx;
      R__b << d1_mNSigmaPion;
      R__b << d1_mNSigmaKaon;
      R__b << d1_mNSigmaProton;
      R__b << d1_mNSigmaElectron;
      R__b << d1_mDCA;
      R__b << d1_mPid;
      R__b << d2_mYLocal;
      R__b << d2_mZLocal;
      R__b << d2_mTof;
      R__b << d2_mMatchFlag;
      R__b << d2_mLength;
      R__b << d2_mPt;
      R__b << d2_mEta;
      R__b << d2_mPhi;
      R__b << d2_mId;
      R__b << d2_mNHitsFit;
      R__b << d2_mNHitsMax;
      R__b << d2_mNHitsDedx;
      R__b << d2_mNSigmaPion;
      R__b << d2_mNSigmaKaon;
      R__b << d2_mNSigmaProton;
      R__b << d2_mNSigmaElectron;
      R__b << d2_mDCA;
      R__b << d2_mPid;
      R__b.SetByteCount(R__c, kTRUE);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_FemtoPair(void *p) {
      return  p ? new(p) ::FemtoPair : new ::FemtoPair;
   }
   static void *newArray_FemtoPair(Long_t nElements, void *p) {
      return p ? new(p) ::FemtoPair[nElements] : new ::FemtoPair[nElements];
   }
   // Wrapper around operator delete
   static void delete_FemtoPair(void *p) {
      delete ((::FemtoPair*)p);
   }
   static void deleteArray_FemtoPair(void *p) {
      delete [] ((::FemtoPair*)p);
   }
   static void destruct_FemtoPair(void *p) {
      typedef ::FemtoPair current_t;
      ((current_t*)p)->~current_t();
   }
   // Wrapper around a custom streamer member function.
   static void streamer_FemtoPair(TBuffer &buf, void *obj) {
      ((::FemtoPair*)obj)->::FemtoPair::Streamer(buf);
   }
} // end of namespace ROOT for class ::FemtoPair

namespace {
  void TriggerDictionaryInitialization_DictionaryFemtoPair_Impl() {
    static const char* headers[] = {
"FemtoPair.h",
0
    };
    static const char* includePaths[] = {
"/Users/jdb/bnl/work/upc/STARLight2PairDst/modules/PairDstFormat/",
"/Users/jdb/bnl/work/upc/STARLight2PairDst/modules/",
"/Users/jdb/bnl/vendor/6.14.04/include",
"/Users/jdb/bnl/work/upc/STARLight2PairDst/",
0
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "DictionaryFemtoPair dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
class __attribute__((annotate("$clingAutoload$FemtoPair.h")))  FemtoPair;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "DictionaryFemtoPair dictionary payload"

#ifndef G__VECTOR_HAS_CLASS_ITERATOR
  #define G__VECTOR_HAS_CLASS_ITERATOR 1
#endif

#define _BACKWARD_BACKWARD_WARNING_H
#include "FemtoPair.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[]={
"FemtoPair", payloadCode, "@",
nullptr};

    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("DictionaryFemtoPair",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_DictionaryFemtoPair_Impl, {}, classesHeaders, /*has no C++ module*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_DictionaryFemtoPair_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_DictionaryFemtoPair() {
  TriggerDictionaryInitialization_DictionaryFemtoPair_Impl();
}
