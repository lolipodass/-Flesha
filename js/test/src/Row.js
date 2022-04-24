import React from "react";

import ReactDOM from "react-dom";

function Row(len, props) {
    const [username, userInput] = useInput({ type: "text" });
    const [password, passwordInput] = useInput({ type: "text" });

    return <>
        {userInput} -> {username} <br />
        {passwordInput} -> {password}
    </>;
}


function useInput({ type /*...*/ }) {
    const [value, setValue] = useState("");
    const input = <input value={value} onChange={e => setValue(e.target.value)} type={type} />;
    return [value, input];
}
export default Row;