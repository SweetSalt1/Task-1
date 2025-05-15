#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "Task.h"

class Employee {
private:
	std::string _name;
	int _hours_in_week;
	std::vector<Task*> _tasks;
public:
	Employee(const std::string& name, int hours_in_week);
	void assign_task(Task* task);
	void remove_task(Task* task);

	const std::string& get_name() const;
	int get_hours_in_week();
	const std::vector<Task*>& get_tasks() const;

	bool is_available() const;
	int total_assigned_hours() const;
};