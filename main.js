const toggleBtn=document.querySelector('.navbar__toggleBtn');
// html안에 있는 togleBtn을 찾아서 const 변수랑 연결해줌
const menu=document.querySelector('.navbar__menu');
const icons=document.querySelector('.navbar__icons');

toggleBtn.addEventListener('click',()=>{
menu.classList.toggle('active');
icons.classList.toggle('active');
});