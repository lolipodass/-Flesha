import { useRef, useState } from 'react';
import "./pico.css"
import './App.css';
import Notes from './components/Notes';

function App() {

  let [name, inputName] = useInput({ type: "text" }, "ФИО");
  let [dateBorn, inputDateBorn] = useInput({ type: "date" }, "Дата рождения");
  let [dateAdmission, inputDateAdmission] = useInput({ type: "date" }, "Дата поступления");
  let [faculty, inputFaculty] = useInput({ type: "text" }, "Факультет");
  let [group, inputGroup] = useInput({ type: "number" }, "Группа");
  let [specialty, inputSpecialty] = useInput({ type: "text" }, "Специальность");
  let [email, inputEmail] = useInput({ type: "email" }, "Email");
  let [phone, inputPhone] = useInput({ type: "tel" }, "Телефон");
  let refPlace = useRef()
  const getAge = birthDate => Math.floor((new Date() - birthDate.getTime()) / 3.15576e+10);




  return (
    <>

      <Notes />
      <form>
        {inputName}
        {inputDateBorn}
        {inputDateAdmission}
        {inputFaculty}
        {inputGroup}
        {inputSpecialty}
        {inputEmail}
        {inputPhone}
      </form>

      <button onClick={show} >показ </button>
      <div ref={refPlace} >

      </div>
    </>
  );


  function show() {
    let date = getAge(new Date(dateAdmission));
    let emailReg = email.match(/@([\S]+)/i);
    console.log(emailReg);
    refPlace.current.innerHTML = (`
      <span>ФИО ${name}</span><br>
      <span>Дата рождения: ${dateBorn} </span><br>
      <span>Возраст ${getAge(new Date(dateBorn))}</span><br>
      <span>Дата поступления${dateAdmission}</span><br>
      <span>Курс: ${date > 4 ? "Закончил" : date}</span><br>
      <span>Специальность: ${specialty}</span><br>
      <span>Группа: ${group}</span><br>
      <span>Факультет: ${faculty}</span><br>
      <span>Email: ${email}</span><br>
      <span>Оператор Email: ${emailReg[1]}</span><br>
      <span>Телефон: ${phone}</span><br>
        `);

    // refPlace.current.innerHTML = `ФИО: ${name}<br>Дата рождения:${dateBorn}<br>Возраст: ${getAge(date)}<br>Дата поступления${dateAdmission}<br>`;
    // refPlace.current.innerHTML = (name, dateBorn, dateAdmission, faculty, group, specialty, email, telephone);
  }

}

function useInput({ type }, label) {
  const [value, setValue] = useState("");
  const input = <label>{label}<input value={value} onChange={e => setValue(e.target.value)} type={type} /></label>;
  return [value, input];
}


export default App;
