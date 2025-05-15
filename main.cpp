#include <iostream>
#include <string>
#include "TaskManager.h"
using namespace std;

int main() {
    TaskManager manager;
    manager.load_file();
    std::cout << endl;
    std::cout << "--- Task Manager ---" << endl;
    bool running = true;

    while (running) {
        std::cout << "Меню: " << endl;
        std::cout << "1. Добавить сотрудника" << endl;
        std::cout << "2. Удалить сотрудника" << endl;
        std::cout << "3. Поиск сотрудника" << endl;
        std::cout << "4. Добавить задачу" << endl;
        std::cout << "5. Удалить задачу" << endl;
        std::cout << "6. Поиск задачи" << endl;
        std::cout << "7. Назначить задачу сотруднику" << endl;
        std::cout << "8. Показать статус задач" << endl;
        std::cout << "9. Пропустить дни" << endl;
        std::cout << "10. Посмотреть занятость всех сотрудников" << endl;
        std::cout << "11. Сохранить" << endl;
        std::cout << "12. Сохранить и выйти" << endl;
        std::cout << "Выберите действие: ";

        int choice;
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1: {
            string name;
            int hours;
            std::cout << "Имя сотрудника: ";
            getline(cin, name);
            std::cout << "Доступные часы в неделю: ";
            cin >> hours;
            manager.add_employee(new Employee(name, hours));
            break;
        }
        case 2: {
            string name;
            std::cout << "Имя сотрудника для удаления: ";
            getline(cin, name);
            Employee* to_delete = nullptr;
            for (Employee* e : manager.get_all_employees()) {
                if (e->get_name() == name) { 
                    to_delete = e; 
                    break; 
                }
            }
            manager.remove_employee(to_delete);
            break;
        }
        case 3: {
            string name;
            std::cout << "Введите имя сотрудника для поиска: ";
            getline(cin, name);

            Employee* found_emp = nullptr;
            for (Employee* e : manager.get_all_employees()) {
                if (e->get_name() == name) {
                    found_emp = e;
                    break;
                }
            }
            if (found_emp) {
                manager.search_employee(found_emp);
            }
            else {
                std::cout << "Сотрудник с именем \"" << name << "\" не найден.\n";
            }
            break;
        }
        case 4: {
            string desc;
            int workload, deadline;
            std::cout << "Описание задачи: ";
            getline(cin, desc);
            std::cout << "Трудоемкость (часы): ";
            cin >> workload;
            std::cout << "Дедлайн (дни): ";
            cin >> deadline;
            cin.ignore();
            Task* task = new Task(desc, workload, deadline, false, nullptr);
            manager.add_task(task);
            break;
        }
        case 5:{
            int id;
            std::cout << "ID задачи для удаления: ";
            cin >> id;
            Task* to_delete = nullptr;
            for (Task* t : manager.get_all_tasks()) {
                if (t->get_id() == id) { 
                    to_delete = t; 
                    break;
                }
            }
            manager.remove_task(to_delete);
            break;
        }
        case 6: {
            int id;
            std::cout << "Введите ID задачи для поиска: ";
            cin >> id;
            cin.ignore();

            manager.search_task(id);
            break;
        }
        case 7: {
            int task_id;
            string emp_name;
            std::cout << "ID задачи: ";
            cin >> task_id;
            std::cout << "Имя сотрудника: ";
            cin.ignore();
            getline(cin, emp_name);

            Task* selected_task = nullptr;
            Employee* selected_emp = nullptr;

            for (Task* t : manager.get_all_tasks()) {
                if (t->get_id() == task_id) {
                    selected_task = t;
                    break;
                }
            }

            for (Employee* e : manager.get_all_employees()) {
                if (e->get_name() == emp_name) {
                    selected_emp = e;
                    break;
                }
            }

            if (selected_task && selected_emp) {
                manager.assign_task_to_employee(selected_task, selected_emp);
                std::cout << "Задача назначена." << endl;
            }
            else {
                std::cout << "Ошибка: задача или сотрудник не найдены." << endl;
            }
            break;
        }
        case 8: {
            manager.see_status();
            break;
        }
        case 9: {
            manager.timeskip();
            break;
        }
        case 10: {
            manager.show_all_employment();
            break;
        }
        case 11: {
            manager.save_file();
            cout << "Данные сохранены." << endl;
            break;
        }
        case 12: {
            manager.save_file();
            running = false;
            break;
        }
        default:
            std::cout << "Неверный выбор." << endl;
            break;
        }
    }

    std::cout << "Завершение работы. Данные сохранены." << endl;

    return 0;
}
