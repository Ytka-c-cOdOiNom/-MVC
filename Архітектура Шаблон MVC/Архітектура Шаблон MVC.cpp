#include <iostream>
#include <windows.h>
using namespace std;

// ----------- Модель -----------
class Model {
private:
    int number1;
    int number2;

public:
    Model() : number1(0), number2(0) {}

    void setNumbers(int n1, int n2) {
        number1 = n1;
        number2 = n2;
    }

    int getSum() const {
        return number1 + number2;
    }
};

// ----------- Представлення -----------
class View {
public:
    void displayResult(int result) {
        cout << "Результат: " << result << endl;
    }
};

// ----------- Контролер -----------
class Controller {
private:
    Model* model;
    View* view;

public:
    Controller(Model* m, View* v) : model(m), view(v) {}

    void setNumbers(int n1, int n2) {
        model->setNumbers(n1, n2);
    }

    void updateView() {
        int result = model->getSum();
        view->displayResult(result);
    }
};

// ----------- Головна функція -----------
int main() {
   
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // Ініціалізація компонентів
    Model model;
    View view;
    Controller controller(&model, &view);

    // Взаємодія з користувачем
    int num1, num2;
    cout << "Введіть перше число: ";
    cin >> num1;
    cout << "Введіть друге число: ";
    cin >> num2;

    // Передаємо дані в модель через контролер
    controller.setNumbers(num1, num2);

    // Оновлюємо представлення через контролер
    controller.updateView();

 
}
