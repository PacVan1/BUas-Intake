#include "UI.h"

UI::UI(int score, int* state) :   
    startButton(fb, "Start Game", { 300.0f, 80.0f }, Color(180, 180, 180, 255), Color::White, 24, 6),  
    restartButton(fb, "Restart Game", { 300.0f, 80.0f }, Color(180, 0, 0, 255), Color::Red, 24, 6), 
    mainButton(fb, "Main Menu", { 300.0f, 80.0f }, Color(180, 180, 180, 255), Color::White, 24, 6), 
    quitButton(fb, "Quit Game", { 300.0f, 80.0f }, Color(180, 0, 0, 255), Color::Red, 24, 6), 
    title("Aysteroids", fb), 
    gameOver("Game Over", fb), 
    minerals("Minerals: " + to_string(score), fr),
    controls("WASD to move - Mouse to aim - Collect Minerals!", fr), 
    gameBy("By: Ayser Hartgring - 05/24", fr),
    state(state)
{
    fr.loadFromFile("GravityRegular5.ttf");
    fb.loadFromFile("GravityBold8.ttf");

    startButton.SetPosition({ 810.0f, 680.0f });
    restartButton.SetPosition({ 810.0f, 700.0f }); 
    mainButton.SetPosition({ 810.0f, 590.0f }); 
    quitButton.SetPosition({ 810.0f, 780.0f }); 

    title.setPosition(610.0f, 300.0f);
    title.setCharacterSize(80);

    gameOver.setPosition(640.0f, 300.0f);
    gameOver.setCharacterSize(80);
    gameOver.setFillColor(Color::Red);

    minerals.setPosition(10.0f, 10.0f); 
    minerals.setCharacterSize(24);

    controls.setPosition(60.0f, 960.0f);
    controls.setCharacterSize(18); 

    gameBy.setPosition(60.0f, 1000.0f);
    gameBy.setCharacterSize(18);
}

void UI::StartScreen(RenderWindow& window)
{
    if (startButton.isMouseOver(window))
    {
        startButton.SetColor(startButton.hoverColor); 
        if (Mouse::isButtonPressed(Mouse::Left))
        {
            *state = 3;  
        }
    }
    else
    {
        startButton.SetColor(startButton.normalColor);  
    }

    if (quitButton.isMouseOver(window))
    {
        quitButton.SetColor(quitButton.hoverColor);
        if (Mouse::isButtonPressed(Mouse::Left))  
        {
            window.close(); 
        }
    }
    else
    {
        quitButton.SetColor(quitButton.normalColor);
    }

    startButton.Draw(window);  
    quitButton.Draw(window);  

    window.draw(title);
    window.draw(controls);
    window.draw(gameBy);
}

void UI::PlayScreen(RenderWindow& window)
{
    window.draw(minerals);
}

void UI::GameOverScreen(RenderWindow& window)
{
    if (restartButton.isMouseOver(window))  
    {
        restartButton.SetColor(restartButton.hoverColor); 
        if (Mouse::isButtonPressed(Mouse::Left)) 
            *state = 3; 
    }
    else
    {
        restartButton.SetColor(restartButton.normalColor); 
    }

    if (mainButton.isMouseOver(window)) 
    {
        mainButton.SetColor(mainButton.hoverColor); 
        if (Mouse::isButtonPressed(Mouse::Left))
            *state = 0; 
    }
    else
    {
        mainButton.SetColor(mainButton.normalColor); 
    }

    restartButton.Draw(window);  
    mainButton.Draw(window);

    window.draw(gameOver);
    window.draw(minerals);
    window.draw(controls);
    window.draw(gameBy);
}
