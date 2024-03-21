let num = 0;

let counter = document.querySelector("#counter");
counter.textContent = num;

const decrement = document.querySelector("#less");
const increment = document.querySelector("#more");
const reset = document.querySelector("#reset");
const theme = document.querySelector("#theme-select");
const body = document.querySelector("body");
const buttons = document.querySelectorAll("button, select");

//window.onclick

decrement.onclick = (e) => {
  num--;
  counter.textContent = num;
};

increment.onclick = (e) => {
  num++;
  counter.textContent = num;
};

reset.onclick = (e) => {
  num = 0;
  counter.textContent = num;
};

theme.onclick = (e) => {
  if (theme.value == "dark") {
    body.style.backgroundColor = "#6f6e6e";
    counter.style.color = "white";

    buttons.forEach((button) => {
      button.style.backgroundColor = "#3e3e3e";
      button.style.color = "white";
    });
  } else if (theme.value == "light") {
    body.style.backgroundColor = "white";
    counter.style.color = "black";

    buttons.forEach((button) => {
      button.style.backgroundColor = "lightgray";
      button.style.color = "black";
    });
  }
};
