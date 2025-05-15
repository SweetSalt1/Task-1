#include "Employee.h"
#include "Task.h"
#include <iostream>
using namespace std;
Employee::Employee(const string& name, int hours_in_day) : _name(name), _hours_in_week(hours_in_day) {}

const string& Employee::get_name() const { return _name; }
int Employee::get_hours_in_day() { return  _hours_in_day; }
const vector<Task*>& Employee::get_tasks() const { return _tasks; }

void Employee::assign_task(Task* task) {
    if (task != nullptr) {
        _tasks.push_back(task);
    }
    task->set_assigned_employee(this);
}

void Employee::remove_task(Task* task) {
    for (int i = 0; i < _tasks.size(); i++) {
        if (_tasks[i] == task) {
            _tasks.erase(_tasks.begin() + i);
            return;
        }
    }
}

bool Employee::is_available() const {
    return total_assigned_hours() < _hours_in_day;
}

int Employee::total_assigned_hours() const {
    int total = 0;
    for (Task* task : _tasks) {
        total += (*task).get_workload_hours();
    }
    return total;
}
