#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
class Employee;

class Task {
private:
	static int _id_counter;
	int _id;
	std::string _description;
	int _workload_hours;
	int _remaining_workload;
	int _deadline_days;
	int _status;
	Employee* _assigned_employee;
public:
	// Без ID
	Task(std::string description, int workload_hours, int deadline_days, int status, Employee* assigned_employee);
	// С ID
	Task(int id, std::string description, int workload_hours, int deadline_days, int status, Employee* assigned_employee);

	static void set_id_counter(int c);

	int get_id() const;
	std::string get_description() const;
	int& get_workload_hours();
	int get_remaining_workload() const;
	void reduce_workload(int hours);
	int& get_deadline_days();
	int get_status() const;
	void set_status(int status);
	Employee* get_assigned_employee();
	void set_assigned_employee(Employee* employee);
};