#ifndef L1TMuonEndCap_TrackAdaptor_hh
#define L1TMuonEndCap_TrackAdaptor_hh

#include "L1Trigger/L1TMuonEndCap/interface/Common.hh"


class TrackAdaptor {
public:
  explicit TrackAdaptor();
  ~TrackAdaptor();

  // Deprecated with new format - AWB 21.02.17

  // void convert_hit(const EMTFHitExtra& in_hit, EMTFHit& out_hit) const;

  // void convert_track(const EMTFTrackExtra& in_track, EMTFTrack& out_track) const;

  // void convert_all(
  //     const EMTFHitExtraCollection& in_hits, const EMTFTrackExtraCollection& in_tracks,
  //     EMTFHitCollection& out_hits, EMTFTrackCollection& out_tracks
  // ) const;

private:
};

#endif
