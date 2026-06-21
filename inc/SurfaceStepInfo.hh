//
// SurfaceStepInfo: MC-truth information of the SurfaceSteps taken by a particle through passive elements, or virtual detectors
//
#ifndef SurfaceStepInfo_HH
#define SurfaceStepInfo_HH
#include "Offline/DataProducts/inc/SurfaceId.hh"
#include "EventNtuple/inc/RootVectors.hh"

namespace mu2e {
  class SurfaceStep;
  struct SurfaceStepInfo {
    int sid=-1; // SurfaceId
    int sindex=-1; // Surface index
    int simid=-1; // SimParticle id (key) of the particle that made this step. With cosmic
                  // resampling the same physical muon crosses different surfaces under different
                  // ids per stage (S1 CRV/concrete vs S2 DS/tracker); these are linked by ancestry.
    float time = 0;  // time the particle enters this component the WRT MC primary proton (ns)
    float edep = 0; // total energy loss through this detector component (MeV)
    float path = 0; // path length take through this detector component (mm)
    XYZVectorF pos;  // particle position at the middle of this step in Detector Coordinates (mm)
    XYZVectorF mom;  // particle momentum at the start of this step (MeV)
    SurfaceStepInfo (const SurfaceStep ss); // construct from a SurfaceStep
    SurfaceStepInfo () {}
  };
}
#endif
