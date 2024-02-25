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

const content2 = document.createElement('div');
content2.classList = 'content2';
content2.style.height = '100px';
content2.style.width = '500px';
content2.style.border = '5px solid black';
content2.style.backgroundColor = 'pink';
container.appendChild(content2);

const contentHeader = document.createElement('h1');
contentHeader.textContent = "I'm in a div";

const contentPara = document.createElement('p');
contentPara.textContent = "ME TOO!"

content2.appendChild(contentHeader);
content2.appendChild(contentPara);

const btn = document.querySelector('#btn');
btn.onclick = () => alert('The onclick property can be used on nodes within the javascript file as well!');

const btn2 = document.querySelector('#btn2');
btn2.addEventListener('click', () => {
	alert('Even better, I can add an event listener to a button which listens for a click. This is the best option due to its flexibility!');
});
