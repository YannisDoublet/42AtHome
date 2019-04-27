import React, {Component} from 'react';
import {connect} from 'react-redux';
import './sign_in.css'

class SignInForm extends Component {

    state = {
        formData: {
            name: {
                element: 'input',
                config: {
                    type: 'text',
                    name: 'firstname',
                    placeholder: 'Firstname',
                    required: true
                },
                value: '',
                touched: false,
                valid: true,
                stage: 1
            },
            lastname: {
                element: 'input',
                config : {
                    type: 'text',
                    name: 'lastname',
                    placeholder: 'Lastname',
                    required: true
                },
                value: '',
                touched: false,
                valid: true,
                stage: 1
            },
            age: {
                element: 'input',
                config: {
                    type: 'text',
                    name: 'age',
                    placeholder: 'Age',
                    required: true
                },
                value: '',
                touched: false,
                valid: true,
                stage: 1
            },
            gender: {
                element: 'select',
                type: 'select',
                name: 'gender',
                required: true,
                touched: false,
                valid: true,
                stage: 1
            },
            sexuality: {
                element: 'select',
                type: 'select',
                name: 'sexuality',
                required: true,
                touched: false,
                valid: true,
                stage: 1
            },
            email: {
                element: 'input',
                config: {
                    type: 'email',
                    name: 'email',
                    placeholder: 'Email',
                    required: true
                },
                value: '',
                touched: false,
                valid: true,
                stage: 2
            },
            username: {
                element: 'input',
                config: {
                    type: 'text',
                    name: 'username',
                    placeholder: 'Username',
                    required: true
                },
                value: '',
                touched: false,
                valid: true,
                stage: 2
            },
            password: {
                element: 'input',
                config: {
                    type: 'password',
                    name: 'password',
                    placeholder: 'Password',
                    required: true
                },
                value: '',
                touched: false,
                valid: true,
                stage: 2
            },
            check_password: {
                element: 'input',
                config: {
                    type: 'password',
                    name: 'check',
                    placeholder: 'Password again',
                    required: true
                },
                value: '',
                touched: false,
                valid: true,
                stage: 2
            }
        }
    };

    fetchStageInput = (evt, stage) => {
        if (stage === 1 || stage === 2) {
            const formArray = [];
            for (let element in this.state.formData) {
                if (stage === this.state.formData[element].stage) {
                    formArray.push({element: this.state.formData[element]});
                }
            }
            return formArray.map((item, i) => {
                return (
                    <div key={i}>{this.renderInput(item)}</div>)
            })
        }
    };

    renderInput = (data) => {
        let inputTemplate = null;

        switch (data.element.element) {
            case('input'):
                inputTemplate = (
                    <div>
                        <input {...data.element.config} value={data.element.value}/>
                    </div>
                );
                break;
            case('select'):
                inputTemplate = <div>Select</div>;
                break;
            default:
                inputTemplate = null;
                break;
        }
        return inputTemplate;
    };

    render() {
        console.log(this.state.formData);
        return (
            <div className={'sign_in_container'}>
                {this.fetchStageInput(null, 1)}
                <button onClick={(e) => this.fetchStageInput(e, 2)}/>
            </div>
        );
    }
}

function mapStateToProps(state) {
    return {};
}

export default connect(mapStateToProps)(SignInForm);
