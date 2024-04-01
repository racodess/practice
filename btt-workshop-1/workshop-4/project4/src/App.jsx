import { useState, useEffect } from "react";
import reactLogo from "./assets/react.svg";
import viteLogo from "/vite.svg";
import "./App.css";

function App() {
  const [num, setNum] = useState(0);
  const [name, setName] = useState("raul");

  const [firstName, setFirstName] = useState("");
  const [comments, setComments] = useState("");

  useEffect(() => {
    console.log(name);
  }, []);

  const handleFirstNameChange = (e) => {
    setFirstName(e.target.value);
    console.log(firstName);
  };

  const handleCommentsChange = (e) => {
    setComments(e.target.value);
    console.log(comments);
  };

  const handleFormSubmit = (e) => {
    e.preventDefault();
    console.log(firstName);
    console.log(comments);
  };

  //[stateVariable, ()=>{}]
  return (
    //<div className="main-container">
    //  <button onClick={() => setNum(num - 1)}>-</button>
    //  <h1>{num}</h1>
    //  <button onClick={() => setNum(num + 1)}>+</button>
    //  <button onClick={() => setName(name + "n")}>N</button>
    //</div>

    <form
      action=""
      className="form-container"
      onSubmit={(e) => handleFormSubmit(e)}
    >
      <label htmlFor="">First Name</label>
      <input
        type="text"
        value={firstName}
        onChange={(e) => handleFirstNameChange(e)}
      />
      <label htmlFor="">Comments</label>
      <textarea
        name=""
        id=""
        cols="30"
        row="10"
        value={comments}
        onChange={(e) => handleCommentsChange(e)}
      ></textarea>
      <button type="submit" className="form-button">
        Submit
      </button>
    </form>
  );
}

export default App;
