#include "crow_all.h"

int main() {
    crow::SimpleApp app;

    // Главная страница кофейни
    CROW_ROUTE(app, "/")
    ([](){
        return "Добро пожаловать в кофейню! Мы рады вас видеть!";
    });

    // Страница с меню
    CROW_ROUTE(app, "/menu")
    ([](){
        return R"(
        <html>
        <body>
            <h1>Меню кофейни</h1>
            <ul>
                <li>Кофе черный - 100 рублей</li>
                <li>Капучино - 120 рублей</li>
                <li>Эспрессо - 80 рублей</li>
                <li>Чай - 60 рублей</li>
            </ul>
        </body>
        </html>
        )";
    });

    // Страница с информацией о кофейне
    CROW_ROUTE(app, "/about")
    ([](){
        return R"(
        <html>
        <body>
            <h1>О нашей кофейне</h1>
            <p>Наша кофейня была основана в 2020 году. Мы предлагаем вкусный кофе и отличный сервис!</p>
        </body>
        </html>
        )";
    });

    // Запускаем сервер на порту 18080
    app.port(18080).multithreaded().run();
}
mkdir build
cd build
cmake ..
make
  ./server
