#include "fsm/timeout_predicate.h"

#include "fsm/timeout_event.h"
#include <lutil/fsm/Machine.hxx>

namespace kuafu {

TimeoutPredicate::TimeoutPredicate(const MachineType& source_machine_type)
:source_machine_type_(source_machine_type) {
}

bool TimeoutPredicate::operator() (const EventSharedPtr& event,
            const MachineBaseSharedPtr& machine) {
   auto tevent = std::dynamic_pointer_cast<TimeoutEvent>(event);
   return (tevent &&
               source_machine_type_ == tevent->GetType() &&
               machine.getName() == tevent->GetMachineName());
}

} //namespace kuafu
