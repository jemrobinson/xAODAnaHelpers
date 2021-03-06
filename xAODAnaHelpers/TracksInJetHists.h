#ifndef xAODAnaHelpers_TracksInJetHists_H
#define xAODAnaHelpers_TracksInJetHists_H

#include "xAODAnaHelpers/HistogramManager.h"
#include <xAODJet/Jet.h>
#include <xAODAnaHelpers/TrackHists.h>

ANA_MSG_HEADER(msgTracksInJetHists)

class TracksInJetHists : public HistogramManager
{
  public:
    TracksInJetHists(std::string name, std::string detailStr );
    ~TracksInJetHists();

    float getD0Sign(const xAOD::TrackParticle* trk, const xAOD::Jet* jet);
    float getZ0Sign(const xAOD::TrackParticle* trk, const xAOD::Jet* jet, const xAOD::Vertex *pvx);

    StatusCode initialize();
    StatusCode execute( const xAOD::TrackParticle* trk, const xAOD::Jet* jet,  const xAOD::Vertex *pvx, float eventWeight, const xAOD::EventInfo* eventInfo );
    using HistogramManager::book; // make other overloaded versions of book() to show up in subclass
    using HistogramManager::execute; // overload
    virtual void record(EL::Worker* wk);

  protected:

  private:

    TrackHists*       m_trkPlots; //!

    // Histograms
    TH1F* m_trk_d0                ; //!
    TH1F* m_trk_d0Sig     	    ; //!
    TH1F* m_trk_d0SigPDF  	    ; //!
    TH2F* m_trk_z0sinTd0  	    ; //!
    TH1F* m_trk_z0_signed         ; //!
    TH1F* m_trk_z0sinT_signed     ; //!
    TH1F* m_trk_z0Sig_signed      ; //!
    TH1F* m_trk_z0Sig_signed_pdf  ; //!
    TH1F* m_trk_z0SigsinT_signed  ; //!
    TH1F* m_trk_jetdPhi 	    ; //!
    TH1F* m_trk_jetdEta 	    ; //!
    TH1F* m_trk_jetdR      	    ; //!
    TH1F* m_trk_jetdR_l              ; //!


};


#endif
