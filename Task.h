#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "Employee.h"

class Task {
private:
	std::string _description;
	int _workload_hours;
	int _deadline_days;
	bool _status;
	Employee* assigned_employee;
public:
	Task(std::string description, int workload_hours, int deadline_days, bool status): _description(description), _workload_hours(workload_hours), _deadline_days(deadline_days), _status(status);
};