void TaskManager::assign_task_to_employee(Task* task, Employee* employee) {
    employee->assign_task(task);
    task->assigned_employee = employee;
}

void TaskManager::see_employment(Employee* employee) {
    if (employee->_tasks.empty()) {
        std::cout << "Employee is free." << std::endl;
    }
    else {
        std::cout << "Employee is busy with tasks." << std::endl;
    }
}

void TaskManager::see_status() {
    for (Task* task : tasks) {
        std::string status = task->_status ? "Ready" : "Not Ready";
        if (task->_deadline_days < 0) status = "Overdue";
        std::cout << "Task: " << task->_description << ". Status: " << status << std::endl;
    }
}

void TaskManager::task_ready() {
    for (Task* task : tasks) {
        if (task->assigned_employee) {
            task->_workload_hours -= task->assigned_employee->_hours_in_week;
            if (task->_workload_hours <= 0) task->_status = true;
        }
    }
}

void TaskManager::end_day() {
    current_day++;
    for (Task* task : tasks) {
        task->_deadline_days--;
    }
}

void TaskManager::timeskip() {
    int days;
    std::cout << "Enter days to skip: ";
    std::cin >> days;
    for (int i = 0; i < days; i++) end_day();
}
