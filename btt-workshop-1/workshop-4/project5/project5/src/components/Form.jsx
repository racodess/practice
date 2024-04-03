const Form = () => {
  const questions = [
    {
      id: 1001,
      questionTitle: "Which fruit is yellow?",
      answers: ["Apple", "Orange", "Lemon", "Strawberry"],
    },
    {
      id: 1002,
      questionTitle: "Which fruit is red?",
      answers: ["Apple", "Orange", "Lemon", "Strawberry"],
    },
  ];

  return (
    <div>
      <h1>The Quiz</h1>

      {questions.map((question) => {
        return (
          <div key={question.id}>
            {question.questionTitle}

            <div>
              {question.answers.map((answer) => {
                return (
                  <div key={answer}>
                    <input type="radio"></input>
                    <label>{answer}</label>
                  </div>
                );
              })}
            </div>
          </div>
        );
      })}
    </div>
  );
};

export default Form;
