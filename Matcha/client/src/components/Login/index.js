import React, {Component} from 'react'
import {Link} from 'react-router-dom'
import './login.css'

import SignInForm from './Sign_in'
import SignUpForm from './Sign_up'

class Login extends Component {

    state = {
        sign_in: true,
        sign_up: false,
        last_clicked: 'sign_in'
    };

    toggleForms = (evt) => {
        if (evt.target.id === 'sign_in' && this.state.sign_in === false) {
            this.setState({
                sign_in: true,
                sign_up: false,
                last_clicked: evt.target.id
            })
        } else if (evt.target.id === 'sign_up' && this.state.sign_up === false) {
            this.setState({
                sign_in: false,
                sign_up: true,
                last_clicked: evt.target.id
            })
        }
    };

    render() {
        console.log(this.state);
        let active = {
            sign_in: this.state.sign_in ? 'active_button' : '',
            sign_up: this.state.sign_up ? 'active_button' : ''
        };
        return (
            <div className={'login_container'}>
                <div className={'login_nav'}>
                    <Link to={'/'}>
                        <img className={'logo2'} src={'/assets/love.svg'} alt={'Logo'}/>
                    </Link>
                    <p className={'title'}>Matcha</p>
                </div>
                <div className="login_content">
                    <div className="login_picture"/>
                    <div className="login_forms">
                        <div className="login_box">
                            <div className={'login_option'}>
                                <div id={'sign_in'} className={`login_sign_in_button ${active.sign_in}`}
                                     onClick={this.toggleForms}>Sign in</div>
                                <div id={'sign_up'} className={`login_sign_up_button ${active.sign_up}`}
                                     onClick={this.toggleForms}>Sign up</div>
                            </div>
                            <div>
                                {this.state.sign_in ? <SignInForm /> : <SignUpForm />}
                            </div>
                        </div>
                    </div>
                </div>
            </div>
        );
    }
}

export default Login;
