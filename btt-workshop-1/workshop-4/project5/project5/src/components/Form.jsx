const Form = () => {
  const questions = [
    {
      id: 10001,
      question: "What fruit is yellow",
      answers: ["Apple", "Orange", "Lemons"],
    },
    {
      id: 10002,
      question: "What color is best?",
      answers: ["Yellow", "Green", "Blue", "Cyan"],
    },
  ];

  return (
    <div>
      <form>
        <h1>The Quiz</h1>
        {questions.map((question) => {
          console.log(question.id);
          return "";
        })}
      </form>
    </div>
  );
};

export default Form;
