#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/MessageLogger/interface/MessageLogger.h"

#include "FWCore/Framework/interface/EventSetup.h"
#include "FWCore/Framework/interface/ESHandle.h"

#include "CondFormats/DataRecord/interface/L1TGlobalPrescalesVetosRcd.h"
#include "CondFormats/L1TObjects/interface/L1TGlobalPrescalesVetos.h"

class L1TGlobalPrescalesVetosReader: public edm::EDAnalyzer {
private:
public:
    virtual void analyze(const edm::Event&, const edm::EventSetup&);

    explicit L1TGlobalPrescalesVetosReader(const edm::ParameterSet& pset) : edm::EDAnalyzer(){ }

    virtual ~L1TGlobalPrescalesVetosReader(void){}
};

void L1TGlobalPrescalesVetosReader::analyze(const edm::Event& iEvent, const edm::EventSetup& evSetup){
    edm::ESHandle<L1TGlobalPrescalesVetos> handle1;
    evSetup.get<L1TGlobalPrescalesVetosRcd>().get( handle1 ) ;
    boost::shared_ptr<L1TGlobalPrescalesVetos> ptr(new L1TGlobalPrescalesVetos(*(handle1.product ())));
    for(unsigned int prescaleSet = 0; prescaleSet < ptr->prescale_table_.size(); prescaleSet++)
        for(unsigned int algoBit = 0; algoBit < ptr->prescale_table_[0].size(); algoBit++)
            std::cout<<" algoBit #"<<algoBit<<" prescale["<<prescaleSet<<"]["<<algoBit<<"] = "<<ptr->prescale_table_[prescaleSet][algoBit]<<std::endl;
}

#include "FWCore/PluginManager/interface/ModuleDef.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/Framework/interface/ModuleFactory.h"

DEFINE_FWK_MODULE(L1TGlobalPrescalesVetosReader);

