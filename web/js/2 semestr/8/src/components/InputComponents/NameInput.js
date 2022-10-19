import React from "react";

function NameInput() {
    return (
        <div className="user_name_input form_group">
            <label htmlFor="user_name">Имя пользователя</label><br />
            <input type="text" id="user_name" placeholder="Введите имя" required/>
        </div>
    );
}

export default NameInput;