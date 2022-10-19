import React from "react";

function SecretWordInput() {
    return (
        <div className="secret_word_input form_group">
            <label htmlFor="secret_word">Секретоное слово</label><br />
            <input type="text" id="secret_word" placeholder="Введите секретное слово" required/>
        </div>
    );
}

export default SecretWordInput;