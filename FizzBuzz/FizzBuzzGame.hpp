#pragma once

#include <optional>
#include <string>

namespace katas {

class FBGame {
public:
    FBGame() { }

    void start() { }

    std::string nextAnswer()
    {
        incrementAnswerCounter();

        if (auto specialAnswer = checkSpecialAnswers()) {
            return *specialAnswer;
        } else {
            return printAnswerCounter();
        }
    }

private:
    void incrementAnswerCounter()
    {
        ++currentAnswer;
    }

    bool isAnswerDivisableBy(int number)
    {
        return (currentAnswer % number) == 0;
    }

    void addWordToAnswerIfDivisableByOrHasGivenNumberInIt(int number, const std::string& word, std::string& answer)
    {
        if (isAnswerDivisableBy(number) || answerHasNumberInIt(number)) {
            answer += word;
        }
    }

    bool answerHasNumberInIt(int number)
    {
        auto printed = printAnswerCounter();
        auto posOfNumber = printed.find(std::to_string(number));
        return (posOfNumber != std::string::npos);
    }

    std::optional<std::string> checkSpecialAnswers()
    {
        std::string answer;
        addWordToAnswerIfDivisableByOrHasGivenNumberInIt(3, "Fizz", answer);
        addWordToAnswerIfDivisableByOrHasGivenNumberInIt(5, "Buzz", answer);
        if (!answer.empty()) {
            return answer;
        }
        return {};
    }

    std::string printAnswerCounter()
    {
        return std::to_string(currentAnswer);
    }

    int currentAnswer { 0 };
};

}
