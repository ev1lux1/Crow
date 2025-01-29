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
                <li>Кофе черный - 15zl</li>
                <li>Капучино - 20zl</li>
                <li>Эспрессо - 10zl</li>
                <li>Чай - 8zl</li>
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
