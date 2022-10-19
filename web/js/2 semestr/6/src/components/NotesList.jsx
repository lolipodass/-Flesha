import React, { useState } from "react";
import NoteItem from "./NoteItem";

const NotesList = ({ notes, changeNote }) => {
 
      return (
        <div>
            <h2> Notelist</h2>
            {notes.map((note, index) =>
                index > 6 ?
                    <NoteItem note={note} styleClass={'noteItemRed'} key={note.id} />
                    : <div onDoubleClick={() =>  changeNote(note) } className="note"><NoteItem note={note}/> </div>
                )}
        </div>
    )
}

export default NotesList