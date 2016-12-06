#ifndef L1TriggerConfig_XmlConfigTools_TriggerSystem_h
#define L1TriggerConfig_XmlConfigTools_TriggerSystem_h

#include <vector>
#include <string>
#include <map>
#include <set>

#include "Parameter.h"
#include "L1Trigger/L1TCommon/interface/Mask.h"

namespace l1t {

class TriggerSystem {
private:
    std::string sysId;

    std::map<std::string, std::string> procToRole;    // map of processors to their roles
    std::map<std::string, std::string> procToSlot;    // map of processors to their slots in some crate
    std::map<std::string, bool>        procEnabled;   // processor is active/disabled (also including daqttc)
    std::map<std::string, std::string> daqttcToRole;  // map of DAQ/TTC boards to their roles
    std::map<std::string, std::string> daqttcToCrate; // map of DAQ/TTC boards to the crates they sit in
    std::map<std::string, std::set<std::string> > roleForProcs;   // map of roles, each describing a set of processors
    std::map<std::string, std::set<std::string> > crateForProcs;  // map of crates, each containing a set of processors
    std::map<std::string, std::set<std::string> > roleForDaqttcs; // map of roles, each describing a set of DAQ/TTC boards

    std::map<std::string, std::map<std::string,Parameter> > procParameters; // setting objects found in the configuration for a given processor
    std::map<std::string, std::map<std::string,Mask> >      procMasks;    // mask objects found in the configuration for a given processor

    bool isConfigured; // lock allowing access to the system 

    mutable std::ostream *logs; // print processing logs unless is set to a null pointer

public:
    void configureSystemFromFiles(const char *hwCfgFile,
                                  const char *topCfgFile,
                                  const char *key) throw() ;

    void addProcessor(const char *processor, const char *role, const char *crate, const char *slot) // must have parameters
            throw( std::runtime_error ) ;

    void addDaq(const char *daq, const char *role, const char *crate) throw(std::runtime_error);

    void addParameter(const char *id,
                      const char *procOrRole,
                      const char *type,
                      const char *value,
                      const char *delim=","
                     ) throw(std::runtime_error);

    void addParameterTable(const char *id,
                           const char *procOrRole,
                           const char *columns,
                           const char *types,
                           const std::vector<std::string>& rows,
                           const char *delim
                          ) throw(std::runtime_error);

    void addMask(const char *id, const char *procOrRoleOrDaq) throw(std::runtime_error);

    void disableProcOrRoleOrDaq(const char *procOrRoleOrDaq) throw(std::runtime_error);

    const std::map<std::string, std::string>&            getProcToRoleAssignment (void) const throw() { return procToRole;   }
    const std::map<std::string, std::set<std::string> >& getRoleToProcsAssignment(void) const throw() { return roleForProcs; }

    const std::map<std::string, Parameter>& getParameters(const char *processor) const throw(std::runtime_error);
    const std::map<std::string, Mask>&      getMasks     (const char *processor) const throw(std::runtime_error);

    bool isMasked     (const char *proccessor, const char *id) const throw(std::runtime_error);
    bool isProcEnabled(const char *proccessor) const throw(std::runtime_error);

    std::string systemId(void) const throw() { return sysId; }
    void setSystemId(const char *id) throw() { sysId = id; }

    void setConfigured(const bool state=true) throw() { isConfigured = state; }
    void setLogStream(std::ostream *s) const throw() { logs = s; }

    TriggerSystem(void){
        isConfigured = false;
        logs = 0;
    }

    ~TriggerSystem(void){}
};

} // end of l1t namespace

#endif

