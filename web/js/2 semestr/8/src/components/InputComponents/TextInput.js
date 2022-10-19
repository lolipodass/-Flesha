import React from "react";

function TextInput() {
    return (
        <div className="text_input form_group">
            <label htmlFor="text">Текст</label><br />
            <textarea id="text" placeholder="Введите текст" required rows={5} cols={71}></textarea>
        </div>
    );
}

export default TextInput;