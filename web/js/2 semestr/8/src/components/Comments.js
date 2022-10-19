import React, {useState} from "react";
import EmailInput from "./InputComponents/EmailInput";
import NameInput from "./InputComponents/NameInput";
import TextInput from "./InputComponents/TextInput";
import SecretWordInput from "./InputComponents/SecretWordInput";
import CommentsList from "./CommentsList";
import "./../styles/Comments.css";

function Comments() {
    const [comments, setComments] = useState([]);
    const [editMode, setEditMode] = useState([false, -1]);

    function addComment(event, commentId) {
        const formData = event.target;
        const dateOfChange = new Date();
        const dayMonthYear = `${dateOfChange.getDate()}-${dateOfChange.getMonth() + 1}-${dateOfChange.getFullYear()}`;
        const hoursMinutes = `${dateOfChange.getHours()}:${dateOfChange.getMinutes()}`;
        let currentComments = comments;

        const comment = {
            userName: formData[0].value,
            userEmail: formData[1].value,
            userSecretWord: formData[2].value,
            userText: formData[3].value,
            commentDateOfChange: `${dayMonthYear} ${hoursMinutes}`
        };

        if (!editMode[0]) {
            setComments((prevState) => [...prevState, comment]);
        }
        else 
        {
            currentComments[commentId] = comment;
            setComments(() => [...currentComments]);
            setEditMode(() => [false, -1]);
        }

        formData[0].value = "";
        formData[1].value = "";
        formData[2].value = "";
        formData[3].value = "";

        return;
    }

    function deleteComment(event) {
        const inputSecretWord = window.prompt("Введите секретное слово для удаления");

        const commentId = +event.target.parentNode.id.replace('comment-','');
        const comment = comments[commentId];
        const secretWord = comment.userSecretWord;
        
        let currentComments = comments;
        (secretWord === inputSecretWord) ? currentComments.splice(commentId, 1) : alert('Секретный код введён неверно');
        
        setComments(() => [...currentComments]);

        return;
    }

    function editComment(event) {
        const commentId = +event.target.parentNode.id.replace('comment-','');
        
        commentId !== editMode[1] ? setEditMode(() => [true, commentId]) : setEditMode(() => [false, -1]);
        
        return;
    }

    function showComment(event) {
        const commentId = +event.target.parentNode.id.replace('comment-','');
        const comment = comments[commentId];
        const info = `${comment.userName}\n${comment.userEmail}\n${comment.commentDateOfChange}`;

        window.alert(info);
    }

    return (
        <div className="wrap">
            {editMode[0] ? <h2>Режим редактирования комментария {editMode[1] + 1}</h2> : null}
            <div className="form">
                <form action="#" id="comment_form" onSubmit={(event) => {addComment(event, editMode[1]); event.preventDefault()}}>
                    <NameInput />
                    <EmailInput />
                    <SecretWordInput />
                    <TextInput />
                    <input type="submit" id="submit"/>
                </form>
            </div>
            <CommentsList comments={comments} deleteFunction={deleteComment} editFunction={editComment} showFunction={showComment} />
            <div id="info"></div>
        </div>
    );
}

export default Comments;