import { useEffect, useRef, useState } from "react";


function Form() {
    const refSubmit = useRef();
    const [progress, setProgress] = useState(0);
    let [password, inputPassword] = useInput({ type: "password" }, "пароль");
    let [rePassword, inputRepassword] = useInput({ type: "password" }, "повторите пароль");
    let [Message, setMessage] = useState('0');

    useEffect(passwordCheck, [password, rePassword]);

    const email = /^[\w-\.]+@([\w-]+\.)+[\w-]{2,4}$/i;

    const passwordRegExp = [
        /\d/,
        /\w/,
        /\S/,
        /\W/,
        /[\w\W]{4,}/,
        /[\w\W]{6,}/,
        /[\w\W]{8,}/,
    ]


    return (
        <form>
            <label> Email<input type="text" onChange={emailCheck} /></label>
            {inputPassword}
            {inputRepassword}
            {Message}
            <progress value={progress} max={passwordRegExp.length}></progress>
            {/* <label> Password<input type="password" onChange={passwordCheck} /></label>
            <label> Type again<input type="password" onChange={passwordCheck} /></label> */}

            <label> Имя<input type="text" /></label>
            <label> Фамилия<input type="text" /></label>
            <label> отчество<input type="text" /></label>
            male < input type="radio" name="da" /> female < input type="radio" name="da" />
            <input type="date" name="da" />
            <input type="submit" value="Send" ref={refSubmit} />

            <br />
        </form >
    )


    function emailCheck(e) {
        if (!email.test(e.target.value))
            toggleSubmit(1)
        else
            toggleSubmit(0);
    }

    function passwordCheck() {
        let amount = 0;
        setProgress(0);
        passwordRegExp.forEach(reg => {
            if (password.match(reg))
                setProgress((prev) => prev + 1);
        });
        console.log(amount);

        if (password != rePassword) {
            toggleSubmit(1);
            setMessage("Different passwords");
        }
        else {
            setMessage();
            toggleSubmit(0);
        }
    }



    function toggleSubmit(value) {
        value ? refSubmit.current.setAttribute("disabled", true) :
            refSubmit.current.removeAttribute("disabled");
    }
}




function useInput({ type }, label) {
    const [value, setValue] = useState("");
    const input = <label>{label}<input value={value} onChange={e => setValue(e.target.value)} type={type} /></label>;
    return [value, input];
}

export default Form;