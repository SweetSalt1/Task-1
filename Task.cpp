#include "Task.h"
using namespace std;
int Task::_id_counter = 0;

// конструктор с id
Task::Task(int id, string description, int workload_hours, int deadline_days, int status, Employee* assigned_employee): 
    _id(id), _description(description), _workload_hours(workload_hours), _remaining_workload(workload_hours), _deadline_days(deadline_days), _status(status), _assigned_employee(assigned_employee){
    if (id > _id_counter) 
        _id_counter = id;
}
// Конструктор без id
Task::Task(std::string description, int workload_hours, int deadline_days, int status, Employee* assigned_employee) : _description(description), _workload_hours(workload_hours), _remaining_workload(workload_hours), _deadline_days(deadline_days), _status(status), _assigned_employee(assigned_employee) {
	_id = ++_id_counter;
}
void Task::set_id_counter(int c) { _id_counter = c; }

int Task::get_id() const { return _id; }
std::string Task::get_description() const { return _description; }
int& Task::get_workload_hours() { return _workload_hours; }
int Task::get_remaining_workload() const { return _remaining_workload; }
void Task::reduce_workload(int hours) { _remaining_workload -= hours; }
int& Task::get_deadline_days() { return _deadline_days; }
int Task::get_status() const { return _status; }
void Task::set_status(int status) { _status = status; }
Employee* Task::get_assigned_employee() { return _assigned_employee; }
void Task::set_assigned_employee(Employee* employee) { _assigned_employee = employee; }
