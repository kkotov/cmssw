// Class for input trigger primitives to EMTF - AWB 04.01.16
// Based on L1Trigger/L1TMuon/interface/deprecate/MuonTriggerPrimitive.h
// In particular, see struct CSCData

#ifndef __l1t_EMTFHit_h__
#define __l1t_EMTFHit_h__

#include <vector>
#include <boost/cstdint.hpp> 
#include <cmath>
#include <iostream>

#include "DataFormats/MuonDetId/interface/CSCDetId.h"
#include "DataFormats/MuonDetId/interface/RPCDetId.h"
#include "DataFormats/CSCDigi/interface/CSCCorrelatedLCTDigi.h"
#include "DataFormats/RPCDigi/interface/RPCDigi.h"
#include "DataFormats/L1TMuon/interface/EMTF/ME.h"

namespace l1t {
  
  class EMTFHit {
  public:
    
  EMTFHit() :
    endcap(-99), station(-99), ring(-99), sector(-99), sector_idx(-99), subsector(-99), 
      chamber(-99), csc_ID(-99), roll(-99), rpc_layer(-99), neighbor(-99), mpc_link(-99),
      pc_sector(-99), pc_station(-99), pc_chamber(-99), pc_segment(-99),
      wire(-99), strip(-99), strip_hi(-99), strip_low(-99), track_num(-99), quality(-99), 
      pattern(-99), bend(-99), valid(-99), sync_err(-99), bc0(-99), bx(-99), stub_num(-99),
      phi_fp(-99), theta_fp(-99), phzvl(-99), ph_hit(-99), zone_hit(-99), zone_code(-99),
      fs_segment(-99), fs_zone_code(-99), bt_station(-99), bt_segment(-99),
      phi_loc_deg(-99), phi_glob_deg(-99), theta_deg(-99), eta(-99),
      is_CSC(-99), is_RPC(-99), subsystem(-99)
      {};
    
    virtual ~EMTFHit() {};

    void ImportCSCDetId (const CSCDetId& _detId);
    CSCDetId CreateCSCDetId();
    void ImportRPCDetId (const RPCDetId& _detId);
    RPCDetId CreateRPCDetId();
    void ImportCSCCorrelatedLCTDigi (const CSCCorrelatedLCTDigi& _digi);
    CSCCorrelatedLCTDigi CreateCSCCorrelatedLCTDigi();
    void ImportRPCDigi (const RPCDigi& _digi);
    RPCDigi CreateRPCDigi();
    void ImportME (const emtf::ME _ME );

    void PrintSimulatorHeader();
    void PrintForSimulator();

    void SetCSCDetId         (CSCDetId id)                 { csc_DetId         = id;        }
    void SetRPCDetId         (RPCDetId id)                 { rpc_DetId         = id;        }
    void SetCSCLCTDigi       (CSCCorrelatedLCTDigi digi)   { csc_LCTDigi       = digi;      }
    void SetRPCDigi          (RPCDigi digi)                { rpc_Digi          = digi;      }
    
    CSCDetId CSC_DetId                          () const { return csc_DetId;    }
    RPCDetId RPC_DetId                          () const { return rpc_DetId;    }
    CSCCorrelatedLCTDigi CSC_LCTDigi            () const { return csc_LCTDigi;  }
    RPCDigi RPC_Digi                            () const { return rpc_Digi;  }

    void set_endcap       (int  bits) { endcap       = bits; }
    void set_station      (int  bits) { station      = bits; }
    void set_ring         (int  bits) { ring         = bits; }
    void set_sector       (int  bits) { sector       = bits; }
    void set_sector_idx   (int  bits) { sector_idx   = bits; }
    void set_subsector    (int  bits) { subsector    = bits; }
    void set_chamber      (int  bits) { chamber      = bits; }
    void set_csc_ID       (int  bits) { csc_ID       = bits; }
    void set_csc_nID      (int  bits) { csc_nID      = bits; }
    void set_roll         (int  bits) { roll         = bits; }
    void set_rpc_layer    (int  bits) { rpc_layer    = bits; }
    void set_neighbor     (int  bits) { neighbor     = bits; }
    void set_mpc_link     (int  bits) { mpc_link     = bits; }
    void set_pc_sector    (int  bits) { pc_sector    = bits; }
    void set_pc_station   (int  bits) { pc_station   = bits; }
    void set_pc_chamber   (int  bits) { pc_chamber   = bits; }
    void set_pc_segment   (int  bits) { pc_segment   = bits; }
    void set_wire         (int  bits) { wire         = bits; }
    void set_strip        (int  bits) { strip        = bits; }
    void set_strip_hi     (int  bits) { strip_hi     = bits; }
    void set_strip_low    (int  bits) { strip_low    = bits; }
    void set_track_num    (int  bits) { track_num    = bits; }
    void set_quality      (int  bits) { quality      = bits; }
    void set_pattern      (int  bits) { pattern      = bits; }
    void set_bend         (int  bits) { bend         = bits; }
    void set_valid        (int  bits) { valid        = bits; }
    void set_sync_err     (int  bits) { sync_err     = bits; }
    void set_bc0          (int  bits) { bc0          = bits; }
    void set_bx           (int  bits) { bx           = bits; }
    void set_stub_num     (int  bits) { stub_num     = bits; }
    void set_phi_fp       (int  bits) { phi_fp       = bits; }
    void set_theta_fp     (int  bits) { theta_fp     = bits; }
    void set_phzvl        (int  bits) { phzvl        = bits; }
    void set_ph_hit       (int  bits) { ph_hit       = bits; }
    void set_zone_hit     (int  bits) { zone_hit     = bits; }
    void set_zone_code    (int  bits) { zone_code    = bits; }
    void set_fs_segment   (int  bits) { fs_segment   = bits; }
    void set_fs_zone_code (int  bits) { fs_zone_code = bits; }
    void set_bt_station   (int  bits) { bt_station   = bits; }
    void set_bt_segment   (int  bits) { bt_segment   = bits; }
    void set_phi_loc_deg  (float val) { phi_loc_deg  = val;  }
    void set_phi_glob_deg (float val) { phi_glob_deg = val;  }
    void set_theta_deg    (float val) { theta_deg    = val;  }
    void set_eta          (float val) { eta          = val;  }
    void set_is_CSC       (int  bits) { is_CSC       = bits; }
    void set_is_RPC       (int  bits) { is_RPC       = bits; }
    void set_subsystem    (int  bits) { subsystem    = bits; }

    int   Endcap       ()  const { return endcap      ; }
    int   Station      ()  const { return station     ; }
    int   Ring         ()  const { return ring        ; }
    int   Sector       ()  const { return sector      ; }
    int   Sector_idx   ()  const { return sector_idx  ; }
    int   Subsector    ()  const { return subsector   ; }
    int   Chamber      ()  const { return chamber     ; }
    int   CSC_ID       ()  const { return csc_ID      ; }
    int   CSC_nID      ()  const { return csc_nID     ; }
    int   Roll         ()  const { return roll        ; }
    int   RPC_layer    ()  const { return rpc_layer   ; }
    int   Neighbor     ()  const { return neighbor    ; }
    int   MPC_link     ()  const { return mpc_link    ; }
    int   PC_sector    ()  const { return pc_sector   ; }
    int   PC_station   ()  const { return pc_station  ; }
    int   PC_chamber   ()  const { return pc_chamber  ; }
    int   PC_segment   ()  const { return pc_segment  ; }
    int   Wire         ()  const { return wire        ; }
    int   Strip        ()  const { return strip       ; }
    int   Strip_hi     ()  const { return strip_hi    ; }
    int   Strip_low    ()  const { return strip_low   ; }
    int   Track_num    ()  const { return track_num   ; }
    int   Quality      ()  const { return quality     ; }
    int   Pattern      ()  const { return pattern     ; }
    int   Bend         ()  const { return bend        ; }
    int   Valid        ()  const { return valid       ; }
    int   Sync_err     ()  const { return sync_err    ; }
    int   BC0          ()  const { return bc0         ; }
    int   BX           ()  const { return bx          ; }
    int   Stub_num     ()  const { return stub_num    ; }
    int   Phi_fp       ()  const { return phi_fp      ; }
    int   Theta_fp     ()  const { return theta_fp    ; }
    int   Phzvl        ()  const { return phzvl       ; }
    int   Ph_hit       ()  const { return ph_hit      ; }
    int   Zone_hit     ()  const { return zone_hit    ; }
    int   Zone_code    ()  const { return zone_code   ; }
    int   FS_segment   ()  const { return fs_segment  ; }
    int   FS_zone_code ()  const { return fs_zone_code; }
    int   BT_station   ()  const { return bt_station  ; }
    int   BT_segment   ()  const { return bt_segment  ; }
    float Phi_loc_deg  ()  const { return phi_loc_deg ; }
    float Phi_glob_deg ()  const { return phi_glob_deg; }
    float Theta_deg    ()  const { return theta_deg   ; }
    int   Eta          ()  const { return eta         ; }
    int   Is_CSC       ()  const { return is_CSC      ; }
    int   Is_RPC       ()  const { return is_RPC      ; }
    int   Subsystem    ()  const { return subsystem   ; }


  private:
    
    CSCDetId csc_DetId;
    RPCDetId rpc_DetId;
    CSCCorrelatedLCTDigi csc_LCTDigi;
    RPCDigi rpc_Digi;
    
    int   endcap      ; // -1 or 1.  Filled in EMTFHit.cc from CSCDetId, modified
    int   station     ; //  1 -  4.  Filled in EMTFHit.cc from CSCDetId
    int   ring        ; //  1 -  3.  Filled in EMTFHit.cc from CSCDetId
    int   sector      ; //  1 -  6.  Filled in EMTFHit.cc from CSCDetId
    int   sector_idx  ; //  0 - 11.  0 - 5 for positive endcap, 6 - 11 for negative.  If a neighbor hit, set by the sector that received it, not the actual sector of the hit.
    int   subsector   ; //  1 -  2.  Filled in EMTFHit.cc or emulator using calc_subsector above
    int   chamber     ; //  1 - 36.  Filled in EMTFHit.cc from CSCDetId
    int   csc_ID      ; //  1 -  9.  Filled in EMTFHit.cc from CSCCorrelatedLCTDigi or emulator from CSCData
    int   csc_nID     ; //  
    int   roll        ; //  Sub-division of ring for RPC hits
    int   rpc_layer   ; //  Forward-backward bit for RPC hits
    int   neighbor    ; //  0 or 1.  Filled in EMTFBlockME.cc 
    int   mpc_link    ; //  1 -  3.  Filled in EMTFHit.cc from CSCCorrelatedLCTDigi
    int   pc_sector   ; //
    int   pc_station  ; // 
    int   pc_chamber  ; // 
    int   pc_segment  ; //
    int   wire        ; //  1 -  ?.  Filled in EMTFHit.cc from CSCCorrelatedLCTDigi
    int   strip       ; //  1 -  ?.  Filled in EMTFHit.cc from CSCCorrelatedLCTDigi
    int   strip_hi    ; //  Highest strip number in an RPC cluster
    int   strip_low   ; //  Lowest strip number in an RPC cluster
    int   track_num   ; //  ? -  ?.  Filled in emulator from CSCData 
    int   quality     ; //  0 - 15.  Filled in EMTFHit.cc from CSCCorrelatedLCTDigi
    int   pattern     ; //  0 - 10.  Filled in EMTFHit.cc from CSCCorrelatedLCTDigi
    int   bend        ; //  0 or 1.  Filled in EMTFHit.cc from CSCCorrelatedLCTDigi
    int   valid       ; //  0 or 1.  Filled in EMTFHit.cc from CSCCorrelatedLCTDigi
    int   sync_err    ; //  0 or 1.  Filled in EMTFHit.cc from CSCCorrelatedLCTDigi
    int   bc0         ; //  0 or 1.
    int   bx          ; //  -3 - 3.  Filled in EMTFHit.cc from CSCCorrelatedLCTDigi
    int   stub_num    ; //  0 or 1.
    int   phi_fp      ;
    int   theta_fp    ;
    int   phzvl       ;
    int   ph_hit      ;
    int   zone_hit    ;
    int   zone_code   ;
    int   fs_segment  ;
    int   fs_zone_code;
    int   bt_station  ;
    int   bt_segment  ;
    float phi_loc_deg ;
    float phi_glob_deg;
    float theta_deg   ;
    int   eta         ;
    int   is_CSC      ; //  0 or 1.  Filled in EMTFHit.cc
    int   is_RPC      ; //  0 or 1.  Filled in EMTFHit.cc
    int   subsystem   ; //

  }; // End of class EMTFHit
  
  // Define a vector of EMTFHit
  typedef std::vector<EMTFHit> EMTFHitCollection;
  
} // End of namespace l1t

#endif /* define __l1t_EMTFHit_h__ */
