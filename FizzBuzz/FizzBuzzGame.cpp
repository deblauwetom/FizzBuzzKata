#include "FizzBuzzGame.hpp"

namespace katas {

FBGame::FBGame() { }

void FBGame::start() { }

std::string FBGame::nextAnswer()
{
    incrementAnswerCounter();

    if (auto specialAnswer = checkSpecialAnswers()) {
        return *specialAnswer;
    } else {
        return printAnswerCounter();
    }
}

void FBGame::incrementAnswerCounter()
{
    ++currentAnswer;
}

bool FBGame::isAnswerDivisableBy(int number)
{
    return (currentAnswer % number) == 0;
}

void FBGame::addWordToAnswerIfDivisableByOrHasGivenNumberInIt(int number, const std::string& word, std::string& answer)
{
    if (isAnswerDivisableBy(number) || answerHasNumberInIt(number)) {
        answer += word;
    }
}

bool FBGame::answerHasNumberInIt(int number)
{
    auto printed = printAnswerCounter();
    auto posOfNumber = printed.find(std::to_string(number));
    return (posOfNumber != std::string::npos);
}

std::optional<std::string> FBGame::checkSpecialAnswers()
{
    std::string answer;
    addWordToAnswerIfDivisableByOrHasGivenNumberInIt(3, "Fizz", answer);
    addWordToAnswerIfDivisableByOrHasGivenNumberInIt(5, "Buzz", answer);
    if (!answer.empty()) {
        return answer;
    }
    return {};
}

std::string FBGame::printAnswerCounter()
{
    return std::to_string(currentAnswer);
}
}
