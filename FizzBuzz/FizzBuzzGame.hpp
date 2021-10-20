#pragma once

#include <optional>
#include <string>

namespace katas {

class FBGame {
public:
    FBGame();

    void start();
    std::string nextAnswer();

private:
    void incrementAnswerCounter();
    bool isAnswerDivisableBy(int number);
    void addWordToAnswerIfDivisableByOrHasGivenNumberInIt(int number, const std::string& word, std::string& answer);
    bool answerHasNumberInIt(int number);
    std::optional<std::string> checkSpecialAnswers();
    std::string printAnswerCounter();

    int currentAnswer { 0 };
};

}
