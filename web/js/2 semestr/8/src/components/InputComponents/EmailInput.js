import React from "react";

function EmailInput() {
    return (
        <div className="email_input form_group">
            <label htmlFor="email">E-mail</label><br />
            <input type="email" id="email" placeholder="Введите E-mail" required/>
        </div>
    );
}

export default EmailInput;