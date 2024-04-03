const Form = () => {
  const questions = [
    {
      id: 1001,
      questionTitle: "Which fruit is yellow?",
      answers: ["Apple", "Orange", "Lemon", "Starberry"],
    },
    {
      id: 1002,
      questionTitle: "Which fruit is red?",
      answers: ["Apple", "Orange", "Lemon", "Starberry"],
    },
  ];

  return (
    <div>
      <h1>The Quiz</h1>

      {questions.map((question) => {
        return <div key={questions.id}>{question.questionTitle}</div>;
      })}
    </div>
  );
};

export default Form;
