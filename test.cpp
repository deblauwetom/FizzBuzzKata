#include <gmock/gmock.h>
#include <gtest/gtest.h>

using namespace testing;
using namespace std;

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
        if (isAnswerDivisableBy(number)) {
            answer += word;
        } else {
            auto printed = printAnswerCounter();
            auto posOfNumber = printed.find(std::to_string(number));
            if (posOfNumber != std::string::npos) {
                answer += word;
            }
        }
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

class FBGameFixture : public Test {
public:
    FBGame game;

    void incrementAnswer(int times)
    {
        for (auto i = 0; i < times; ++i) {
            game.nextAnswer();
        }
    }
};

class FBGameStartedFixture : public FBGameFixture {
public:
    FBGameStartedFixture()
    {
        game.start();
    }
};

TEST_F(FBGameFixture, GivenNewGame_WhenStarting_ThenStartAtOne)
{
    //Given

    //When
    game.start();

    EXPECT_THAT(game.nextAnswer(), Eq("1"));
}

TEST_F(FBGameStartedFixture, WhenNextAnswer_ThenIncrementAnswerByOne)
{
    //When
    game.nextAnswer();

    //Then
    EXPECT_THAT(game.nextAnswer(), Eq("2"));
}

TEST_F(FBGameStartedFixture, GivenNextAnswerDivisableBy3_WhenNextAnswer_ThenPrintFizz)
{
    incrementAnswer(2);

    //when
    auto next = game.nextAnswer();

    //then
    EXPECT_THAT(next, Eq("Fizz"));
}

TEST_F(FBGameStartedFixture, GivenNextAnswerDivisableBy5_WhenNextAnswer_ThenPrintBuzz)
{
    incrementAnswer(4);

    //when
    auto next = game.nextAnswer();

    //then
    EXPECT_THAT(next, Eq("Buzz"));
}

TEST_F(FBGameStartedFixture, GivenNextAnswerDivisableBy5AndBy3_WhenNextAnswer_ThenPrintFizzBuzz)
{
    incrementAnswer(14);

    //when
    auto next = game.nextAnswer();

    //then
    EXPECT_THAT(next, Eq("FizzBuzz"));
}

TEST_F(FBGameStartedFixture, GivenNextAnswerHasA3InTheNumber_WhenNextAnswer_ThenPrintFizz)
{
    incrementAnswer(30);

    //when
    auto next = game.nextAnswer();

    //then
    EXPECT_THAT(next, Eq("Fizz"));
}

TEST_F(FBGameStartedFixture, GivenNextAnswerHasA5InTheNumber_WhenNextAnswer_ThenPrintBuzz)
{
    incrementAnswer(55);

    //when
    auto next = game.nextAnswer();

    //then
    EXPECT_THAT(next, Eq("Buzz"));
}

TEST(RealProgram, Output)
{
    FBGame game;
    game.start();
    for (auto i = 0; i < 100; ++i) {
        std::cout << game.nextAnswer() << std::endl;
    }
}
