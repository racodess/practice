const container = document.querySelector('#container');

const content = document.createElement('div');
content.classList.add('content');
content.textContent = 'This is the text-content!';

container.appendChild(content);

const paragraph = document.createElement('p');
paragraph.textContent = "Hey i'm red!";
paragraph.style.color = 'red';
container.appendChild(paragraph);

const body = document.querySelector('body');
const h3 = document.createElement('h3');
h3.textContent = "I'm a blue h3!";
h3.style.color = 'blue';
body.insertBefore(h3, container);
