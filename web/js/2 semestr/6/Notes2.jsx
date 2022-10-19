
import { useId, useRef, useState } from "react"
import "../App.css"
import useInput from "./useInput.js"


function Notes() {
  let [header, inputHeader] = useInput({ type: "text" }, "Заголовок")
  let [body, inputBody] = useInput({ type: "text" }, "Тело заметки")
  const [arrNotes, setNote] = useState([]);
  function addNote() {
    const key = Math.random();
    const note = useNote(header, body,key);
    setNote((arr) =>  [arr,note]);
  }
  function delNote()
  {
    setNote((arr) => { arr.pop();
return [arr]});
  }

  
  return (
    <div className="menu">
      <div className="buttons">
        {inputHeader}
        {inputBody}
        <button onClick={addNote}> добавить заметку</button>
        <button onClick={delNote}> удалить заметку</button>
      </div>
      <div className="place">{arrNotes}</div>
    </div>
  )





  function useNote(header, value,key) {

    return (<div className="note" key={key}>
      <header>{header}</header>
      <div>{value}</div>
    </div>)
  }
}
export default Notes; 