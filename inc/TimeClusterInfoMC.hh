//
// MC truth for a reconstructed time cluster: which SimParticle actually made its hits.
//
// A TimeCluster is the hit set track finding hands to the fitter, so it exists whether or not
// the subsequent fit succeeded. Truth-matching it therefore gives an MC-level denominator that
// is independent of reconstruction success -- unlike trkmc/trkhitsmc, which are stored inside
// the KalSeed(MC) and so only exist once a track has been fit.
//
#ifndef EventNtuple_TimeClusterInfoMC_hh
#define EventNtuple_TimeClusterInfoMC_hh
#include "EventNtuple/inc/SimInfo.hh"
namespace mu2e {
  struct TimeClusterInfoMC {
    int nsh = 0;            // cluster straw hits successfully resolved to a StrawDigiMC
    int nsh_prim = 0;       // of those, the number made by the dominant SimParticle
    int nsim = 0;           // distinct SimParticles contributing to the cluster
    float purity = -1.0f;   // nsh_prim / (cluster nStrawHits); -1 if the cluster has no hits
    SimInfo prim;           // the dominant SimParticle (pdg, id, gen, origin mom/pos, ...)
    void reset() { *this = TimeClusterInfoMC(); }
  };
}
#endif
