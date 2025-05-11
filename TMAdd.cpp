
	void add_task() {

		//Оглавление переменн для добавления
		std::string pdescription;
        	int pworkload_hours;
        	int pdeadline_days;
        	bool pstatus;

		//Запрос описания задачи. getline считывает строку и записывает ее в description
		std::cout<<"Введите описание задачи: ";
		std::getline(std::cin, pdescription);

		//Запрос трудозатратности
		std::cout<<"Введите трудозатратность в часах: ";
		std::cin>>pworkload_hours;

		//Запрос срока выполнения
		std::cout<<"Введите срок выполнения в днях: ";
		std::cin>>pdeadline_days;

		//Запрос статуса задачи
		std::cout<<"Ведите статус задачи (0 - не выполнена, 1 - выполнена): ";
		std::cin>>pstatus;

		//Добавление задачи в вектор Task (newTask???)
		Task* newTask(pdescription, pworkload_hours, pdeadline_days, pstatus);
		tasks.push_back(newTask);
		std::cout<<"Задача добавлена."<<std::endl;
	};
	void remove_task() {
		int index;
		std::cout<<"Введите индекс задачи: "; //Запрос индекса задачи
		std::cin>>index;
		if (index >=0 && index < tasks.size()) { //Проверка индекса на положительные значения и на допустимый диапозон
			tasks.erase(tasks.begin()+index); //Удаление элемента при указанном индексе.
			std::cout<<"Задача удалена.\n";}
		else {
			std::cout<<"Неверный индекс.\n";}
	};
	void search_task() {
		std::string search;
		std::cout<<"Введите строку для поиска: "; //Запрос строки
		std::getline(std::cin, search);
		int tmp1=0; //Вспомогательная переменная
		for (size_t i=0; i<tasks.size(); i++) {
			if (tasks[i].description==search) { //Сравнивание строк(???)
				std::cout<<"Результат поиска: "<<i<<std::endl;
				tmp1+=1;}}
		if (tmp1==0) {
			std::cout<<"Ничего не найдено.\n";}
	};
