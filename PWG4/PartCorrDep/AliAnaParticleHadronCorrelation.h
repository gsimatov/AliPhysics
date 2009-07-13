#ifndef ALIANAPARTICLEHADRONCORRELATION_H
#define ALIANAPARTICLEHADRONCORRELATION_H
/* Copyright(c) 1998-1999, ALICE Experiment at CERN, All rights reserved. *
 * See cxx source for full Copyright notice     */
/* $Id:  $ */

//_________________________________________________________________________
// Class that contains the algorithm for the analysis of particle - hadron correlations
// Particle (for example direct gamma) must be found in a previous analysis 
//-- Author: Gustavo Conesa (INFN-LNF)

// --- ROOT system ---
class TH2F;

// --- Analysis system ---
#include "AliAnaPartCorrBaseClass.h"
class AliAODPWG4ParticleCorrelation ;

class AliAnaParticleHadronCorrelation : public AliAnaPartCorrBaseClass {
  
 public: 
  
  AliAnaParticleHadronCorrelation() ; // default ctor
  AliAnaParticleHadronCorrelation(const AliAnaParticleHadronCorrelation & ph) ; // cpy ctor
  AliAnaParticleHadronCorrelation & operator = (const AliAnaParticleHadronCorrelation & ph) ;//cpy assignment
  virtual ~AliAnaParticleHadronCorrelation() {;} //virtual dtor
  
  TList * GetCreateOutputObjects();
  
  Double_t GetDeltaPhiMaxCut() const {return fDeltaPhiMaxCut ; }
  Double_t GetDeltaPhiMinCut() const {return fDeltaPhiMinCut ; }
  void SetDeltaPhiCutRange(Double_t phimin, Double_t phimax)
  {fDeltaPhiMaxCut =phimax;  fDeltaPhiMinCut =phimin;}

  Double_t GetUeDeltaPhiMaxCut() const {return fUeDeltaPhiMaxCut ; }
  Double_t GetUeDeltaPhiMinCut() const {return fUeDeltaPhiMinCut ; }
  void SetUeDeltaPhiCutRange(Double_t uephimin, Double_t uephimax)
  {fUeDeltaPhiMaxCut =uephimax;  fUeDeltaPhiMinCut =uephimin;}
  Bool_t IsSeveralUEOn() const {return fMakeSeveralUE ; }
  void SwitchOnSeveralUECalculation()  { fMakeSeveralUE = kTRUE;}
  void SwitchOffSeveralUECalculation() { fMakeSeveralUE = kFALSE;}

  Bool_t OnlyIsolated() const {return fSelectIsolated ; }
  void SelectIsolated(Bool_t select) {fSelectIsolated = select ; }
  
  void InitParameters();
  
  void Print(const Option_t * opt) const;
  
  void MakeChargedCorrelation(AliAODPWG4ParticleCorrelation * aodParticle,TRefArray* pl, const Bool_t bFillHisto) ;
  void MakeNeutralCorrelationFillAOD(AliAODPWG4ParticleCorrelation * aodParticle, TRefArray* pl, TString detector)  ;
  void MakeNeutralCorrelationFillHistograms(AliAODPWG4ParticleCorrelation * aodParticle)  ;
	
  void MakeAnalysisFillAOD()  ;
  void MakeAnalysisFillHistograms() ; 
  
  Bool_t SelectCluster(AliAODCaloCluster * calo, Double_t *vertex, TLorentzVector & mom, Int_t & pdg) const ;
  
 private:
  
  Double_t   fDeltaPhiMaxCut ;      // Minimum Delta Phi Gamma-Hadron
  Double_t   fDeltaPhiMinCut ;      // Maximum Delta Phi Gamma-Hadron
  Bool_t     fSelectIsolated ;      // Select only trigger particles isolated
  Bool_t   fMakeSeveralUE ; // Do analysis for several underlying events contribution
  Double_t   fUeDeltaPhiMaxCut ;      // Minimum Delta Phi Gamma-Underlying Hadron
  Double_t   fUeDeltaPhiMinCut ;      // Maximum Delta Phi Gamma-Underlying Hadron

  
  //Histograms
  TH2F * fhPhiCharged  ; //! Phi distribution of selected charged particles
  TH2F * fhPhiNeutral   ;  //! Phi distribution of selected neutral particles
  TH2F * fhEtaCharged  ; //! Eta distribution of selected charged particles
  TH2F * fhEtaNeutral   ; //! Eta distribution of selected neutral particles
  TH2F * fhDeltaPhiCharged  ;  //! Difference of charged particle phi and trigger particle  phi as function of  trigger particle pT
  TH2F * fhDeltaPhiNeutral   ;  //! Difference of neutral particle phi and trigger particle  phi as function of  trigger particle pT
  TH2F * fhDeltaEtaCharged  ;  //! Difference of charged particle eta and trigger particle  eta as function of  trigger particle pT
  TH2F * fhDeltaEtaNeutral  ;  //! Difference of neutral particle eta and trigger particle  eta as function of  trigger particle pT
  TH2F * fhDeltaPhiChargedPt  ;  //! Difference of charged particle phi and trigger particle  phi as function of charged particle pT
  TH2F * fhDeltaPhiNeutralPt  ;  //! Difference of neutral particle phi and trigger particle  phi as function of neutral particle particle pT
  TH2F * fhDeltaPhiUeChargedPt  ;  //! Difference of charged particle from underlying events phi and trigger particle  phi as function of charged particle pT
  TH2F * fhDeltaPhiUeNeutralPt  ;  //! Difference of neutral particle phi and trigger particle  phi as function of neutral particle particle pT

  TH2F * fhPtImbalanceNeutral  ; //! Trigger particle - neutral hadron momentum imbalance histogram 
  TH2F * fhPtImbalanceCharged  ; //! Trigger particle -charged hadron momentim imbalance histogram
  TH2F * fhPtImbalanceUeCharged  ; //! Trigger particle -underlying charged hadron momentim imbalance histogram  
  TH2F * fhPtImbalanceUeNeutral  ; //! Trigger particle - neutral hadron momentum imbalance histogram 

//if several UE calculation is on, most useful for jet-jet events contribution
  TH2F * fhDeltaPhiUeLeftCharged  ;  //! Difference of charged particle from underlying events phi and trigger particle  phi as function of charged particle pT
  TH2F * fhDeltaPhiUeRightCharged  ;  //! Difference of charged particle from underlying events phi and trigger particle  phi 
  TH2F * fhDeltaPhiUeLeftNeutral  ;  //! Difference of charged particle from underlying events phi and trigger particle  phi as function of neutral particle pT
  TH2F * fhDeltaPhiUeRightNeutral  ;  //! Difference of charged particle from underlying events phi and trigger particle  phi 
  TH2F * fhPtImbalanceUeLeftCharged  ; //! Trigger particle -underlying charged hadron momentim imbalance histogram 
  TH2F * fhPtImbalanceUeRightCharged  ; //! Trigger particle -underlying charged hadron momentim imbalance histogram  
  TH2F * fhPtImbalanceUeLeftNeutral  ; //! Trigger particle -underlying neutral hadron momentim imbalance histogram 
  TH2F * fhPtImbalanceUeRightNeutral  ; //! Trigger particle -underlying neutral hadron momentim imbalance histogram  
  ClassDef(AliAnaParticleHadronCorrelation,2)
} ;
 

#endif //ALIANAPARTICLEHADRONCORRELATION_H



