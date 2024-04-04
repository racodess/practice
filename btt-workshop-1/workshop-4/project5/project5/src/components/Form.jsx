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

  const [userAnswers, setUserAnswer] = useState({
    1001: null,
    1002: null,
  });

  function handleFormSubmit(event) {
    event.preventDefault();
  }

  function handleUserClickNewAnswer(id, answer) {
    const tempVar = userAnswers;
    tempVar[id] = answer;

    setUserAnswers(tempVar);
  }

  return (
    <form onSubmit={handleFormSubmit}>
      <h1>The Quiz</h1>

      {questions.map((question) => {
        return (
          <div key={question.id}>
            {question.questionTitle}

            <div>
              {question.answers.map((answer) => {
                return (
                  <div key={answer}>
                    <input
                      type="radio"
                      name={question.id}
                      onChange={(event) =>
                        handleUserClickNewAnswer(question.id, answer)
                      }
                    ></input>
                    <label>{answer}</label>
                  </div>
                );
              })}
            </div>
          </div>
        );
      })}
      <button>Submit Quiz</button>
    </form>
  );
};

export default Form;
