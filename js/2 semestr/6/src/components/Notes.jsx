import React, {useEffect, useState} from 'react'
import NotesList from "./NotesList";
import './styleshit.css'

const Notes = ({ vision, note_date }) => {
    const [but, setBut] = useState(false);
    const [d, setD] = useState(0);
    const [notes, setNotes] = useState([])

    const [note, setNote] = useState({ title: '', text: '', date: note_date })

    const [warning, setWarning] = useState('')

    const addNewNote = (e) => {
        e.preventDefault()
        if (!but) {
            if (note.title === '')
                alert('Input note title!')
            else {
                note.date = note_date;
                setNotes([...notes, { ...note, id: Date.now() }])
                console.log(notes);
            }
        }
        else {
            notes.map((p, index) => {
                if (p.id == d)
                {
                    p.title = note.title;
                    p.text = note.text
                }
            });
            setBut(false);
        }
    }


    const changeNote = (not) => {
        setNote({ title: not.title, text: not.text, date: not.date })
        setD(not.id);
        setBut(true);
    }
    
    const deleteFirstNote = (e) => {
        e.preventDefault()
        setNotes(notes.filter((p, index) => index !== 0))
    }

    const deleteLastNote = (e) => {
        e.preventDefault()
        setNotes(notes.filter((p, index) => index !== notes.length - 1))
    }

    const deleteAllNotes = (e) => {
        e.preventDefault()
        setNotes(notes.filter((p, index) => index == -1))
    }

    const deleteSomeNotes = (e) => {
        e.preventDefault()
        setNotes(notes.filter((p, index) => p.date != note_date));
       
    }


    useEffect(() => {
        if(notes.length < 8)
            setWarning('')
        else
            setWarning('you have a lot of notes')
    }, [notes])

    return (
        <div className={vision}>
            <form className={'noteForm'}>
                <h2 style={{ color: 'black' }}>Notes</h2>
                <h3 style={{color:'red'}}>{warning}</h3>
                <input style={{borderColor:'grey', borderRadius:'0px', marginLeft:'0px'}}
                    className={'noteInput'}
                    type="text"
                    placeholder={'Title'}
                    value={note.title}
                    onChange={e => setNote({...note, title: e.target.value})}
                />
                <input style={{borderColor:'grey', borderRadius:'0px', marginLeft:'0px'}}
                    className={'noteInput'}
                    type="text"
                    placeholder={'Description'}
                    value={note.text}
                    onChange={e => setNote({...note, text: e.target.value})}
                />
              
                {
                    notes.length > 3 ?
                        <>
                            <button onClick={deleteFirstNote} >Delete first</button> 
                            <button onClick={addNewNote} >New note</button> 
                            <button onClick={deleteLastNote} >Delete last</button>
                        </>
                        :
                        <>
                            <button onClick={addNewNote} > New note</button> 
                            <button onClick={deleteAllNotes} > Delete all notes</button> 
                            <button onClick={deleteSomeNotes} > Delete these notes</button> 
                        </>
                }
            </form>
            <br/>

            <NotesList changeNote={changeNote} notes={notes} />
        </div>
    )
}

export default Notes
