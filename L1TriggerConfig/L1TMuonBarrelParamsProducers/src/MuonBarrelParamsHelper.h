#ifndef L1T_MUON_BARREL_PARAMS_HELPER_h
#define L1T_MUON_BARREL_PARAMS_HELPER_h

#include <cassert>
#include "CondFormats/L1TObjects/interface/L1TMuonBarrelParams.h"
#include "L1Trigger/L1TCommon/interface/TrigSystem.h"

// If you want to create a new object that you can read and write, use this constructor:
//
//   l1t::MuonBarrelParamsHelper x(new L1TMuonBarrelParams());
//
// If you wish to read the table from the EventSetup, and will only read, use this:
//
//   const MuonBarrelParamsHelper* x = MuonBarrelParamsHelper::readFromEventSetup(...)
//   //...
//   delete x;
//
// If you wish to read the table from the EventSetup, but then be able to edit the values locally, use this:
//
//   MuonBarrelParamsHelper* x = MuonBarrelParamsHelper::readAndWriteFromEventSetup(...)
//   //...
///  delete x;
//
// but there's a performance penalty as a copy is made.

//
// This class does not take over responsibility for deleting the pointers it is
// initialized with.  That is responsibility of the calling code.
//


namespace l1t {

class MuonBarrelParamsHelper : public {
private:
    // separating read from write allows for a high-performance read-only mode (as no copy is made):
    const L1TMuonBarrelParams* read_;  // when reading/getting, use this.
          L1TMuonBarrelParams* write_; // when writing/setting, use this.     
    bool we_own_write_;

    void useCopy(void){
        write_ = new L1TMuonBarrelParams(*read_);
        we_own_write_ = true;
        read_ = write_;
    }
    void check_write(void) { assert(write_); }

    typedef std::map<short, short, std::less<short> > LUT;

    // L1MuDTPtaLut::load:
    int load_pt (std::vector<MuonBarrelParamsHelper::LUT>& , std::vector<int>&,  unsigned short int, std::string);
    // L1MuDTPhiLut::load:
    int load_phi(std::vector<MuonBarrelParamsHelper::LUT>& , unsigned short int, unsigned short int, std::string);
    // L1MuDTExtLut::load:
    int load_ext(std::vector<L1TMuonBarrelParams::LUTParams::extLUT>&, unsigned short int, unsigned short int );

    // disallow construction from a const object
    MuonBarrelParamsHelper(const L1TMuonBarrelParams *es){} 

public:

    // The two main methods of configuring the contained payload
    void configFromPy( std::map<std::string, int>&  allInts,
                       std::map<std::string, bool>& allBools,
                       std::map<std::string, std::vector<std::string> > allMasks,
                       unsigned int fwVersion,
                       const std::string& AssLUTpath);
    void configFromDB(l1t::TrigSystem& trgSys);


		std::string AssLUTPath() const  { return read_->pnodes_[L1TMuonBarrelParams::CONFIG].sparams_.size() > 0 ? read_->pnodes_[L1TMuonBarrelParams::CONFIG].sparams_[0] : ""; };
		void setAssLUTPath        (std::string path) { pnodes_[L1TMuonBarrelParams::CONFIG].sparams_.push_back(path); };

		void setpta_lut(std::vector<MuonBarrelParamsHelper::LUT> ptalut) { write_->lutparams_.pta_lut_ = ptalut; };
		std::vector<MuonBarrelParamsHelper::LUT> pta_lut() const {return read_->lutparams_.pta_lut_; };
		void setpta_threshold(std::vector<int> ptathresh) { write_->lutparams_.pta_threshold_ = ptathresh;  };
		std::vector<int> pta_threshold() const { return read_->lutparams_.pta_threshold_;  };

		void setphi_lut(std::vector<MuonBarrelParamsHelper::LUT> philut) { write_->lutparams_.phi_lut_ = philut; };
		std::vector<MuonBarrelParamsHelper::LUT> phi_lut() const {return read_->lutparams_.phi_lut_; };

		void setext_lut(std::vector<LUTParams::extLUT> extlut) { write_->lutparams_.ext_lut_ = extlut; };
		std::vector<LUTParams::extLUT> ext_lut() const {return read_->lutparams_.ext_lut_; };

		void setqp_lut(qpLUT qplut) { write_->lutparams_.qp_lut_ = qplut; };
		qpLUT qp_lut() const {return read_->lutparams_.qp_lut_; };

		void seteta_lut(etaLUT eta_lut) { write_->lutparams_.eta_lut_ = eta_lut; };
		etaLUT eta_lut() const {return read_->lutparams_.eta_lut_; };


		void set_PT_Assignment_nbits_Phi(int par1) {write_->pnodes_[L1TMuonBarrelParams::CONFIG].iparams_[PT_Assignment_nbits_Phi] = par1;};
		void set_PT_Assignment_nbits_PhiB(int par1) {write_->pnodes_[L1TMuonBarrelParams::CONFIG].iparams_[PT_Assignment_nbits_PhiB] = par1;};
		void set_PHI_Assignment_nbits_Phi(int par1) {write_->pnodes_[L1TMuonBarrelParams::CONFIG].iparams_[PHI_Assignment_nbits_Phi] = par1;};
		void set_PHI_Assignment_nbits_PhiB(int par1) {write_->pnodes_[L1TMuonBarrelParams::CONFIG].iparams_[PHI_Assignment_nbits_PhiB] = par1;};
		void set_Extrapolation_nbits_Phi(int par1) {write_->pnodes_[L1TMuonBarrelParams::CONFIG].iparams_[Extrapolation_nbits_Phi] = par1;};
		void set_Extrapolation_nbits_PhiB(int par1) {write_->pnodes_[L1TMuonBarrelParams::CONFIG].iparams_[Extrapolation_nbits_PhiB] = par1;};
		void set_BX_min(int par1) {write_->pnodes_[L1TMuonBarrelParams::CONFIG].iparams_[BX_min] = par1;};
		void set_BX_max(int par1) {write_->pnodes_[L1TMuonBarrelParams::CONFIG].iparams_[BX_max] = par1;};
		void set_Extrapolation_Filter(int par1) {write_->pnodes_[L1TMuonBarrelParams::CONFIG].iparams_[Extrapolation_Filter] = par1;};
		void set_OutOfTime_Filter_Window(int par1) {write_->pnodes_[L1TMuonBarrelParams::CONFIG].iparams_[OutOfTime_Filter_Window] = par1;};
		void set_OutOfTime_Filter(bool par1) {write_->pnodes_[L1TMuonBarrelParams::CONFIG].iparams_[OutOfTime_Filter] = par1;};
		void set_Open_LUTs(bool par1) {write_->pnodes_[L1TMuonBarrelParams::CONFIG].iparams_[Open_LUTs] = par1;};
		void set_EtaTrackFinder(bool par1) {write_->pnodes_[L1TMuonBarrelParams::CONFIG].iparams_[EtaTrackFinder] = par1;};
		void set_Extrapolation_21(bool par1) {write_->pnodes_[L1TMuonBarrelParams::CONFIG].iparams_[Extrapolation_21] = par1;};
		void set_DisableNewAlgo(bool par1) {write_->pnodes_[L1TMuonBarrelParams::CONFIG].iparams_[DisableNewAlgo] = par1;};


		int get_PT_Assignment_nbits_Phi() const{return read_->pnodes_[L1TMuonBarrelParams::CONFIG].iparams_[PT_Assignment_nbits_Phi];};
		int get_PT_Assignment_nbits_PhiB() const {return read_->pnodes_[L1TMuonBarrelParams::CONFIG].iparams_[PT_Assignment_nbits_PhiB];};
		int get_PHI_Assignment_nbits_Phi() const {return read_->pnodes_[L1TMuonBarrelParams::CONFIG].iparams_[PHI_Assignment_nbits_Phi];};
		int get_PHI_Assignment_nbits_PhiB() const {return read_->pnodes_[L1TMuonBarrelParams::CONFIG].iparams_[PHI_Assignment_nbits_PhiB];};
		int get_Extrapolation_nbits_Phi() const {return read_->pnodes_[L1TMuonBarrelParams::CONFIG].iparams_[Extrapolation_nbits_Phi];};
		int get_Extrapolation_nbits_PhiB() const {return read_->pnodes_[L1TMuonBarrelParams::CONFIG].iparams_[Extrapolation_nbits_PhiB];};
		int get_BX_min() const {return read_->pnodes_[L1TMuonBarrelParams::CONFIG].iparams_[BX_min] ;};
		int get_BX_max() const {return read_->pnodes_[L1TMuonBarrelParams::CONFIG].iparams_[BX_max];};
		int get_Extrapolation_Filter() const {return read_->pnodes_[L1TMuonBarrelParams::CONFIG].iparams_[Extrapolation_Filter];};
		int get_OutOfTime_Filter_Window() const {return read_->pnodes_[L1TMuonBarrelParams::CONFIG].iparams_[OutOfTime_Filter_Window] ;};


		bool get_OutOfTime_Filter() const {return read_->pnodes_[L1TMuonBarrelParams::CONFIG].iparams_[OutOfTime_Filter];};
		bool get_Open_LUTs() const {return read_->pnodes_[L1TMuonBarrelParams::CONFIG].iparams_[Open_LUTs] ;};
		bool get_EtaTrackFinder() const {return read_->pnodes_[L1TMuonBarrelParams::CONFIG].iparams_[EtaTrackFinder] ;};
		bool get_Extrapolation_21() const {return read_->pnodes_[L1TMuonBarrelParams::CONFIG].iparams_[Extrapolation_21] ;};
		bool get_DisableNewAlgo() const {return read_->pnodes_[L1TMuonBarrelParams::CONFIG].iparams_[DisableNewAlgo] ;};

		unsigned fwVersion() const { return read_->fwVersion_; };
		void setFwVersion(unsigned fwVersion) { write_->fwVersion_ = fwVersion; };


    //create for reading only, from the EventSetup:
    static const MuonBarrelParamsHelper* readFromEventSetup(const L1TMuonBarrelParams* es){ return new MuonBarrelParamsHelper(es); }
    // create for reading and writing, starting from the EventSetup:
    static       MuonBarrelParamsHelper* readAndWriteFromEventSetup(const L1TMuonBarrelParams* es){
        MuonBarrelParamsHelper* x = new MuonBarrelParamsHelper(es);
        x->useCopy();
        return x;
    }

    // access to underlying pointers, mainly for ESProducer:
    const L1TMuonBarrelParams* getReadInstance(void) const { return read_;  }
          L1TMuonBarrelParams* getWriteInstance(void)      { return write_; }

    PrescalesVetosHelper(L1TMuonBarrelParams* w){
        write_ = w;
        check_write();
        we_own_write_ = false;
        read_ = write_;
    }
    ~PrescalesVetosHelper(void){ if (we_own_write_ && write_) delete write_; }
};

} // end of l1t namespace

#endif
