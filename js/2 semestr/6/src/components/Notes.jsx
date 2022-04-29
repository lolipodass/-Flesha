
// import "../app.css"
import {useInput} from "./useInput.js"


function Notes()
{
  let [header,inputHeader]=useInput({type:"text"},"Заголовок")
  let [body,inputBody]=useInput({type:"text"},"Тело заметки")

  
  return (
    <div>
      {inputHeader}
      {inputBody}
      <button> добавить заметку</button>
      <button> удалить заметку</button>

    </div>
  )
}



function note(header,value)
{
  return (<div className="note">
    <header>{header}</header>
    <div>{value}</div>
  </div>)
}

export default Notes;