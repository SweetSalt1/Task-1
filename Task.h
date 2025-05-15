#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
class Employee;

/**
 * @brief Класс, представляющий задачу.
 */

class Task {
private:
	static int _id_counter;			///< Глобальный счетчик ID
	int _id;						///< Уникальный идентификатор задачи
	std::string _description;		///< Описание задачи
	int _workload_hours;			///< Общая трудоемкость задачи
	int _remaining_workload;		///< Оставшиеся часы
	int _deadline_days;				///< Количество дней до дедлайна
	int _status;					///< Статус задачи
	Employee* _assigned_employee;	///< Назначенный сотрудник
public:
	/**
	 * @brief Конструктор с заданным ID.
	 * @param id Уникальный ID
	 * @param description Описание
	 * @param workload_hours Трудоемкость
	 * @param deadline_days Дедлайн
	 * @param status Статус
	 * @param assigned_employee Назначенный сотрудник
	 */
	Task(std::string description, int workload_hours, int deadline_days, int status, Employee* assigned_employee);
	/**
	 * @brief Конструктор без ID (автоматически генерируется).
	 */
	Task(int id, std::string description, int workload_hours, int deadline_days, int status, Employee* assigned_employee);

	/**
	 * @brief Установить текущий счетчик ID.
	 * @param c Новое значение счетчика
	 */
	static void set_id_counter(int c);

	int get_id() const;								///< Получить ID
	std::string get_description() const;			///< Получить описание
	int& get_workload_hours();						///< Получить ссылку на трудоемкость
	int get_remaining_workload() const;				///< Получить оставшиеся часы
	/**
	 * @brief Уменьшает оставшуюся трудоёмкость.
	 * @param hours Количество часов для вычитания.
	 */
	void reduce_workload(int hours);
	int& get_deadline_days();						///< Получить ссылку на дедлайн
	int get_status() const;							///< Получить статус
	/**
	 * @brief Устанавливает статус задачи.
	 * @param status Новый статус.
	 */
	void set_status(int status);
	Employee* get_assigned_employee();				///< Получить назначенного сотрудника
	void set_assigned_employee(Employee* employee);	///< Назначить сотрудника
};
