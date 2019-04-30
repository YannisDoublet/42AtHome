import React, {Component} from 'react';
import {connect} from 'react-redux';
import './sign_up.css'

// Fonction pour envvoyer les values dans le prochain composant pour tout envoyer en validation au back
// et controler le form avec la validation (si non valide, ne pas update le state donc ne pas changer de composant)
// Faire le select.
// Faire le Sign-in / Forget-password etc

import SignUpStep1 from './sign_up_step_1'
import SignUpStep2 from "./sign_up_step_2";

class SignUpForm extends Component {

    state = {
        stage: 1,
        firstname: {
            required: true,
            valid: true,
            touched: false,
            value: ''
        },
        lastname: {
            required: true,
            valid: true,
            touched: false,
            value: ''
        },
        age: {
            required: true,
            valid: true,
            touched: false,
            value: ''
        },
        gender: {
            required: true,
            valid: true,
            touched: false,
            value: ''
        },
        sexuality: {
            required: false,
            valid: true,
            touched: false,
            value: ''
        },
        email: {
            required: true,
            valid: true,
            touched: false,
            value: ''
        },
        username: {
            required: true,
            valid: true,
            touched: false,
            value: ''
        },
        password: {
            required: true,
            valid: true,
            touched: false,
            value: ''
        },
        check_password: {
            required: true,
            valid: true,
            touched: false,
            value: ''
        }
    };

    handleStage = (stage) => {
        stage === 1 ? this.setState({stage: stage + 1}) : this.setState({stage: stage - 1});
    };

    inputValidation = () => {

    };


    handleChange = (evt) => {
        const {name, value} = evt.target;
        console.log(this.state[name]);
        this.setState({
            ...this.state[name],
            [name]: value
        })
    };

    submitForm = () => {

    };

    render() {
        const stage = this.state.stage;
        return (
            <div>
                {stage === 1 ? <SignUpStep1 data={{
                        firstname: this.state.firstname,
                        lastname: this.state.lastname,
                        age: this.state.age,
                        gender: this.state.gender,
                        sexuality: this.state.sexuality
                    }} stage={stage} change={this.handleChange} handleStage={this.handleStage}/>
                    : <SignUpStep2 data={{
                        email: this.state.email,
                        username: this.state.username,
                        password: this.state.password,
                        check_password: this.state.check_password
                    }} stage={stage} change={this.handleChange} handleStage={this.handleStage} submit={this.submitForm}/>}
            </div>
        );
    }
}

function mapStateToProps(state) {
    return {};
}

export default connect(mapStateToProps)(SignUpForm);
